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

int dhanda_txn_init(char *dbfilepath);
int dhanda_txn_add(struct txn *txn);
int dhanda_txn_findbyid(int id, struct txn *txn);
int dhanda_txn_search(char *query, struct dhanda_list *list);
int dhanda_txn_get(struct dhanda_list *list, int items, int page);
int dhanda_txn_findbytype(struct dhanda_list *list, int type);
int dhanda_txn_getstat(struct txn_stat *txn_stat, struct txn_filter *txn_filter);

#endif

