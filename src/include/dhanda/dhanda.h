#ifndef _DHANDA_H_
#define _DHANDA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>

#include <dhanda/list.h>
#include <dhanda/util.h>

#define MAXLINE 1000
#define MAXCMDARG 32
#define DHANDA_DATA_STORAGE ".dhanda"
#define DHANDA_PARTY_DB_FILE "party.db"
#define DHANDA_TXN_DB_FILE "txn.db"

enum context {
	SCREEN_HOME = 1,
	SCREEN_PARTY,
	SCREEN_PARTY_CREATE,
	SCREEN_PARTY_LIST,
	SCREEN_PARTY_SHOW,
	SCREEN_PARTY_EDIT,
	SCREEN_PARTY_DELETE,
	SCREEN_TXN,
	SCREEN_TXN_CREATE,
	SCREEN_TXN_LIST,
	SCREEN_TXN_SHOW,
};

typedef struct cmdline {
	char cmdline[MAXLINE];
	int cmdline_len;
	char *cmd;
	int argc;
	char *argv[MAXCMDARG];
} cmdline;

typedef struct dhanda {
	FILE *party_fp;
	FILE *txn_fp;
	cmdline cmd;
	enum context context;
	void (*renderer)(struct dhanda *);

	struct list *party_list;
	struct list *txn_list;
} dhanda;

void dhanda_init_app(dhanda *app);
void dhanda_app_cleanup(dhanda *app);

void dhanda_app_print_helpline(dhanda *app);
void dhanda_parse_cmd_line(cmdline *cmd);
void dhanda_app_cmd_handle(dhanda *app);
void dhanda_app_render(dhanda *app);

#endif
