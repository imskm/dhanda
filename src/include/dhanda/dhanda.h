#ifndef _DHANDA_H_
#define _DHANDA_H_

struct dhanda {
	FILE *party_fp;
	FILE *txn_fp;
};

struct dhanda_list {
	// @TODO
};

void dhanda_init_app(struct dhanda *app);

void dhanda_ui_home(struct dhanda *app);
void dhanda_ui_party_list(struct dhanda *app);
void dhanda_ui_party_show(struct dhanda *app);
void dhanda_ui_party_create(struct dhanda *app);
void dhanda_ui_party_edit(struct dhanda *app);
void dhanda_ui_txn_list(struct dhanda *app);
void dhanda_ui_txn_show(struct dhanda *app);
void dhanda_ui_txn_create(struct dhanda *app);
void dhanda_ui_txn_edit(struct dhanda *app);


#include <dhanda/txn.h>


#endif
