#ifndef _DHANDA_H_
#define _DHANDA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include <dhanda/list.h>
#include <dhanda/util.h>

#define MAXLINE 1000
#define MAXCMDARG 32

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
} dhanda;

void dhanda_init_app(dhanda *app);
void dhanda_app_print_helpline(dhanda *app);
void dhanda_parse_cmd_line(cmdline *cmd);
void dhanda_app_cmd_handle(dhanda *app);
void dhanda_app_render(dhanda *app);

void dhanda_command_party_ui(dhanda *app);
void dhanda_command_txn_ui(dhanda *app);
void dhanda_command_exit(dhanda *app);

#endif
