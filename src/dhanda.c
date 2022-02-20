#include <dhanda/dhanda.h>
#include <dhanda/ui.h>
#include <dhanda/party.h>
#include <dhanda/txn.h>

static struct {
	char *cmd;
	void (*handle)(dhanda *);
} commands[] = {
	{ "p", 					dhanda_command_party_ui },
	{ "party", 				dhanda_command_party_ui },
	{ "t", 					dhanda_command_txn_ui },
	{ "txn", 				dhanda_command_txn_ui },
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

	ui_home(&app);
	while (!quit) {
		/* 1. Show command line for the current screen */
		dhanda_app_print_helpline(&app);

		/* 2. Read command line input */
		printf("> ");
		len = get_line(line, MAXLINE);
		app.cmd.cmdline_len = len;
		if (len >= MAXLINE) {
			fprintf(stderr, "Error: command line is unexpectedly long.\n");
			continue;
		}
		dhanda_parse_cmd_line(&app.cmd);

		/* 3. Handle the command (Update app) */
		dhanda_app_cmd_handle(&app);

		/* 4. Render the screen */
		if (!quit) {
			dhanda_app_render(&app);
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
}

void
dhanda_app_print_helpline(dhanda *app)
{
	/* @TODO According to screen context print correct command help line */
	printf("CMD: ");
	printf("p[arty]    t[xn]");
	puts("");
}

void
dhanda_parse_cmd_line(cmdline *cmd)
{
	char *p, *q;
	int i;

	cmd->cmdline[cmd->cmdline_len - 1] = '\0';
	p = cmd->cmdline;
	i = 0;
	while ((q = strchr(p, ' '))) {
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
	for (int i = 0; commands[i].cmd; ++i) {
		if (strcmp(app->cmd.argv[0], commands[i].cmd) == 0) {
			commands[i].handle(app);
			return;
		}
	}

	fprintf(stderr, "Error: command '%s' not found\n", app->cmd.argv[0]);
}

void
dhanda_app_render(dhanda *app)
{
}

void
dhanda_command_party_ui(dhanda *app)
{
	printf("PARTY UI\n");
}

void
dhanda_command_txn_ui(dhanda *app)
{
	printf("TRANSACTION UI\n");
}

void
dhanda_command_exit(dhanda *app)
{
	/* @TODO Clean app */
	quit = 1;
}
