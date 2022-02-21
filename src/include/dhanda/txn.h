#ifndef _DHANDA_TXN_H_
#define _DHANDA_TXN_H_

#include <dhanda/dhanda.h>

typedef struct txn {
	int id;
	int amount;
	time_t cat;
	int type;
	char desc[256];
} txn;

typedef struct txn_stat {
	// @TODO
} txn_stat;

typedef struct txn_filter {
	int page;
	int items;
	// @TODO
} txn_filter;

int txn_init(dhanda *app);
int txn_add(dhanda *app, txn *txn);
int txn_findbyid(dhanda *app, int id, txn *result);
int txn_search(dhanda *app, char *query, struct list *result);
int txn_get(dhanda *app, txn_filter filter, struct list *result);
int txn_findbytype(dhanda *app, int type, struct list *result);
int txn_getstat(dhanda *app, txn_filter filter, txn_stat *result);

#endif

