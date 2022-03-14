#include <dhanda/dhanda.h>
#include <dhanda/ui.h>
#include <dhanda/party.h>
#include <dhanda/txn.h>
#include <dhanda/cursor.h>

/* Theses functions are like controller */
static void dhanda_command_party_home(dhanda *app);
static void dhanda_command_txn_home(dhanda *app);
static void dhanda_command_exit(dhanda *app);
static void dhanda_command_add(dhanda *app);
static void dhanda_command_list(dhanda *app);
static void dhanda_command_show(dhanda *app);
static void dhanda_command_edit(dhanda *app);
static void dhanda_command_delete(dhanda *app);
static void dhanda_command_back(dhanda *app);
static void dhanda_command_search(dhanda *app);

static void dhanda_resolve_add_renderer(dhanda *app);
static void dhanda_resolve_list_renderer(dhanda *app);
static void dhanda_resolve_show_renderer(dhanda *app);
static void dhanda_resolve_search_renderer(dhanda *app);
static void dhanda_resolve_edit_renderer(dhanda *app);
static void dhanda_resolve_delete_renderer(dhanda *app);

void dhanda_app_reset(dhanda *app);


static struct {
	char *cmd;
	void (*handle)(dhanda *);
	void (*renderer)(dhanda *);
	int  resolver;
} commands[] = {
	{ "p", 				dhanda_command_party_home, 	ui_party_list, 0 },
	{ "party", 			dhanda_command_party_home, 	ui_party_list, 0 },
	{ "t", 				dhanda_command_txn_home, 		ui_txn_list, 0 },
	{ "txn", 			dhanda_command_txn_home, 		ui_txn_list, 0 },
	{ "back", 			dhanda_command_back },

	/* Theses commands are contextual based (meaning theses commands are
	 * same for other screens), so it will inspect which function to call
	 * based on context inside which it is run */
	{ "add", 			dhanda_command_add, 		dhanda_resolve_add_renderer, 1 },
	{ "list", 			dhanda_command_list, 		dhanda_resolve_list_renderer, 1 },
	{ "show", 			dhanda_command_show, 		dhanda_resolve_show_renderer, 1 },
	{ "search", 		dhanda_command_search, 		dhanda_resolve_search_renderer, 1 },
	{ "edit", 			dhanda_command_edit, 		dhanda_resolve_edit_renderer, 1 },
	{ "delete", 		dhanda_command_delete, 		dhanda_resolve_delete_renderer, 1 },


	{ "exit", 				dhanda_command_exit },

	{ NULL, NULL }
};

static int quit;

int main(int argc, char *argv[])
{
	int len;
	struct dhanda app = {};
	char *line;

	line = app.cmd.cmdline;
	dhanda_init_app(&app);

	/* @NOTE REPL (Read-Eval-Print-Loop) */
	dhanda_app_render(&app);
	while (!quit) {
		/* 1. Read command line input */
		start_cmdline_color();
		len = get_line(line, MAXLINE);
		/* @NOTE Empty line */
		if (len == 1) continue;
		end_cmdline_color();
		app.cmd.cmdline_len = len;
		if (len >= MAXLINE) {
			fprintf(stderr, "Error: command line is unexpectedly long.\n");
			continue;
		}
		dhanda_parse_cmd_line(&app.cmd);

		/* 2. Handle the command (Update app logic) */
		debug_print("command ran");
		dhanda_app_cmd_handle(&app);

		/* 3. Render the screen */
		if (!quit) {
			dhanda_app_render(&app);
			dhanda_app_reset(&app);
		}
	}
	//ui_party_list(&app);
	//ui_party_show(&app);
	//ui_party_create(&app);
	//ui_party_edit(&app);

	return 0;
}

void
dhanda_init_app(struct dhanda *app)
{
	int ret;
	struct stat buf;
	struct passwd *pw;
	char base_path[256], party_filepath[256], txn_filepath[256];

	/* Setup data storage directory (in user's home dir) */
	if ((pw = getpwuid(getuid())) == NULL) {
		perror("getpwuid error");
		exit(EXIT_FAILURE);
	}
	/* @DANGEROUS BUFFER OVERFLOW upto below */
	strcpy(base_path, pw->pw_dir);
	strcat(base_path, "/");
	strcat(base_path, DHANDA_DATA_STORAGE);
	if ((ret = stat(base_path, &buf)) == -1 && errno == ENOENT) {
		if (mkdir(base_path, 0700) == -1) {
			perror("mkdir error");
			exit(EXIT_FAILURE);
		}
	} else if (ret == -1) {
		perror("Storage create error");
		exit(EXIT_FAILURE);
	}

	app->context = SCREEN_HOME;

	strcpy(party_filepath, base_path);
	strcat(party_filepath, "/");
	strcat(party_filepath, DHANDA_PARTY_DB_FILE);

	strcpy(txn_filepath, base_path);
	strcat(txn_filepath, "/");
	strcat(txn_filepath, DHANDA_TXN_DB_FILE);

	app->party_fp = fopen(party_filepath, "r+b");
	app->txn_fp   = fopen(txn_filepath, "r+b");

	if (app->party_fp == NULL && errno == ENOENT)
		app->party_fp = fopen(party_filepath, "w+b");
	if (app->txn_fp == NULL && errno == ENOENT)
		app->txn_fp = fopen(txn_filepath, "w+b");

	if (app->party_fp == NULL) {
		fprintf(stderr, "Error in file '%s': %s\n", party_filepath, strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (app->txn_fp == NULL) {
		fprintf(stderr, "Error in file '%s': %s\n", txn_filepath, strerror(errno));
		exit(EXIT_FAILURE);
	}

	app->party_list = list_create(sizeof(party));
	app->txn_list 	= list_create(sizeof(txn));

	if (app->party_list == NULL) {
		perror("Failed to create party list");
		exit(EXIT_FAILURE);
	}
	if (app->txn_list == NULL) {
		perror("Failed to create txn list");
		exit(EXIT_FAILURE);
	}

	/* Setup inital app renderer (the home screen) */
	app->renderer = ui_home;
}

void
dhanda_app_cleanup(dhanda *app)
{
}

void
dhanda_app_reset(dhanda *app)
{
	list_delete_all(app->party_list);
	list_delete_all(app->txn_list);
}

void
dhanda_app_print_helpline(dhanda *app)
{
	/* @TODO Improve it. This is not the right way. Build a better structure to store
	 * all the relevent commands for the appropriate context in one central place and
	 * use that struct (like commands) to show it here */
	printf("CMD: ");
	if (app->context == SCREEN_HOME)
		printf("p[arty]    t[xn]");
	else if (app->context == SCREEN_PARTY)
		printf("p[arty]    t[xn]    add    list    show party_id    edit party_id    delete party_id    search query");
	else if (app->context == SCREEN_TXN)
		printf("p[arty]    t[xn]    add    list    show txn_id    search query");
	else
		printf("**UNKNOWN SCREEN**\n");
	puts("\n");
	start_cmdline_color();
	printf("> ");
	end_cmdline_color();
}

void
dhanda_parse_cmd_line(cmdline *cmd)
{
	char *p, *q;
	int i;

	cmd->cmdline[cmd->cmdline_len - 1] = '\0';
	p = cmd->cmdline;
	i = 0;
	while (i < MAXCMDARG - 1 && (q = strchr(p, ' '))) {
		cmd->argv[i++] = p;
		*q = '\0';
		p = q + 1;
	}
	cmd->argv[i++] = p;
	cmd->argc = i;
	cmd->cmd = cmd->argv[0];
	cmd->argv[cmd->argc] = NULL;
}

void
dhanda_app_cmd_handle(dhanda *app)
{
	debug_print("command handler");
	for (int i = 0; commands[i].cmd; ++i) {
		if (strcmp(app->cmd.argv[0], commands[i].cmd) == 0) {
			if (commands[i].resolver) {
				debug_print("renderer called");
				commands[i].renderer(app);
			}
			else {
				app->renderer = commands[i].renderer;
			}
			debug_print("command handler called");
			commands[i].handle(app);
			return;
		}
	}

	fprintf(stderr, "Error: command '%s' not found\n", app->cmd.argv[0]);
}

void
dhanda_app_render(dhanda *app)
{
	/* Clear the screen */
	clear();
	if (app->renderer) {
		app->renderer(app);
	}

	cur_tobottom();
	cur_toleft();
	cur_up(3);
	/* Show command line help for the current screen */
	dhanda_app_print_helpline(app);
}

static void
dhanda_command_party_home(dhanda *app)
{
	debug_print("");
	party_filter filter = {
		.page=1,
		.items=10,
	};
	party_get(app, filter, app->party_list);
	/* Set party context (since user entered in party screen) to perform
	 * operations on party */
	app->context = SCREEN_PARTY;
}

static void
dhanda_command_txn_home(dhanda *app)
{
	debug_print("");
	txn_filter filter = {
		.page=1,
		.items=10,
	};
	txn_get(app, filter, app->txn_list);
	app->context = SCREEN_TXN;
}

static void
dhanda_command_back(dhanda *app)
{
}

static void
dhanda_command_exit(dhanda *app)
{
	debug_print("");
	/* @TODO Clean app */
	quit = 1;
}

static void
dhanda_command_add(dhanda *app)
{
	debug_print("");
	party p;
	txn t;

	switch (app->context) {
		case SCREEN_PARTY:
			/* Insert blank party in the list that will be used by ui_party_create
			 * to populate party details (read from user) and then that party present
			 * in the linked list will be used to pass that to party_add function
			 * to store that in DB. Same goes for transaction below */
			ui_party_create(app);
			party_add(app, party_first_in_list(app));
			break;

		case SCREEN_TXN:
			ui_txn_create(app);
			txn_add(app, txn_first_in_list(app));
			break;
	}
}

static void
dhanda_command_list(dhanda *app)
{
	party_filter pfilter = {
		.page=1, .items=10,
	};
	txn_filter tfilter = {
		.page=1, .items=10,
	};

	debug_print("");

	switch (app->context) {
		case SCREEN_PARTY:
			party_get(app, pfilter, app->party_list);
			break;

		case SCREEN_TXN:
			txn_get(app, tfilter, app->txn_list);
			break;
	}
}

static void
dhanda_command_show(dhanda *app)
{
	party p;
	txn t;
	Node *node;
	int id;
	int ret;

	debug_print("");
	assert(app->cmd.argc == 2);

	id = atoi(app->cmd.argv[1]);
	switch (app->context) {
		case SCREEN_PARTY:
			ret = party_findbyid(app, id, &p);
			assert(ret == 1);

			party_insert_in_list(app, &p);
			break;

		case SCREEN_TXN:
			ret = txn_findbyid(app, id, &t);
			assert(ret == 1);
			txn_insert_in_list(app, &t);
			break;
	}
}

static void
dhanda_command_edit(dhanda *app)
{
	int id, ret;
	party p, *new_party;
	Node *node;

	debug_print("");
	assert(app->cmd.argc == 2);

	id = atoi(app->cmd.argv[1]);
	switch (app->context) {
		case SCREEN_PARTY:
			ret = party_findbyid(app, id, &p);
			if (ret == -1) {
				fprintf(stderr, "party_findbyid error\n");
				return;
			} else if (ret == 0) {
				fprintf(stderr, "party '%d' not found\n", id);
				return;
			}
			party_insert_in_list(app, &p);
			/* This second insert will be treated as blank party (new_party) */
			party_insert_in_list(app, &p);

			ui_party_edit(app);

			new_party = party_second_in_list(app);
			ret = party_update(app, &p, new_party);
			if (ret == -1) {
				fprintf(stderr, "party_udpate error\n");
				return;
			}

			break;
		/* @NOTE Edit for TXN is not allowed */
		default:
			/* @TODO Remove it latter */
			fprintf(stderr, "EDITING TXN NOT ALLOWED\n");
			break;
	}
}

static void
dhanda_command_delete(dhanda *app)
{
	int id, ret;
	party p, *new_party;
	Node *node;

	debug_print("");
	assert(app->cmd.argc == 2);

	id = atoi(app->cmd.argv[1]);
	switch (app->context) {
		case SCREEN_PARTY:
			ret = party_findbyid(app, id, &p);
			if (ret == -1) {
				fprintf(stderr, "party_findbyid error\n");
				return;
			} else if (ret == 0) {
				fprintf(stderr, "party '%d' not found\n", id);
				return;
			}
			party_insert_in_list(app, &p);
			ui_party_delete(app);
			ret = party_delete(app, &p);
			if (ret == -1) {
				fprintf(stderr, "party_delete error\n");
				return;
			}

			/* @TODO Delete all txns of party p */

			break;
		/* @NOTE Edit for TXN is not allowed */
		default:
			/* @TODO Remove it latter */
			fprintf(stderr, "EDITING TXN NOT ALLOWED\n");
			break;
	}
}

static void
dhanda_command_search(dhanda *app)
{
	int ret;
	char *query;

	debug_print("");
	assert(app->cmd.argc == 2);

	query = app->cmd.argv[1];
	switch (app->context) {
		case SCREEN_PARTY:
			ret = party_search(app, query, app->party_list);
			if (ret == -1) {
				fprintf(stderr, "party_findbyid error\n");
				return;
			} else if (ret == 0) {
				fprintf(stderr, "No match for query '%s' found\n", query);
				return;
			}

			break;
		/* @NOTE Edit for TXN is not allowed */
		case SCREEN_TXN:
			/* @TODO What will be the query for txn? */
			fprintf(stderr, "(TODO)\n");
			break;
	}
}

static void
dhanda_resolve_add_renderer(dhanda *app)
{
	debug_print("");
	switch (app->context) {
		case SCREEN_PARTY: 	app->renderer = ui_party_show; break;
		case SCREEN_TXN: 	app->renderer = ui_txn_show; break;
		default: app->renderer = NULL;
	}
}

static void
dhanda_resolve_list_renderer(dhanda *app)
{
	debug_print("");
	switch (app->context) {
		case SCREEN_PARTY: 	app->renderer = ui_party_list; break;
		case SCREEN_TXN: 	app->renderer = ui_txn_list; break;
		default: app->renderer = NULL;
	}
}

static void
dhanda_resolve_show_renderer(dhanda *app)
{
	debug_print("");
	switch (app->context) {
		case SCREEN_PARTY: 	app->renderer = ui_party_show; break;
		case SCREEN_TXN: 	app->renderer = ui_txn_show; break;
		default: app->renderer = NULL;
	}
}

static void
dhanda_resolve_search_renderer(dhanda *app)
{
	debug_print("");
	switch (app->context) {
		case SCREEN_PARTY: 	app->renderer = ui_party_list; break;
		case SCREEN_TXN: 	app->renderer = ui_txn_list; break;
		default: app->renderer = NULL;
	}
}

static void
dhanda_resolve_edit_renderer(dhanda *app)
{
	debug_print("");
	switch (app->context) {
		case SCREEN_PARTY: 	app->renderer = ui_party_show; break;
		default: app->renderer = NULL;
	}
}

static void
dhanda_resolve_delete_renderer(dhanda *app)
{
	debug_print("");
	switch (app->context) {
		case SCREEN_PARTY: 	app->renderer = ui_party_list; break;
		default: app->renderer = NULL;
	}
}


