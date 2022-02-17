#ifndef _DHANDA_TXN_H_
#define _DHANDA_TXN_H_

#include <dhanda/dhanda.h>

struct txn {
	// @TODO
};

struct txn_stat {
	// @TODO
};

struct txn_filter {
	// @TODO
};

int dhanda_txn_init(struct dhanda *app);
int dhanda_txn_add(struct dhanda *app, struct txn *txn);
int dhanda_txn_findbyid(struct dhanda *app, int id, struct txn *txn);
int dhanda_txn_search(struct dhanda *app, char *query, struct list *list);
int dhanda_txn_get(struct dhanda *app, struct list *list, int items, int page);
int dhanda_txn_findbytype(struct dhanda *app, struct list *list, int type);
int dhanda_txn_getstat(struct dhanda *app, struct txn_stat *txn_stat, struct txn_filter *txn_filter);

#endif

