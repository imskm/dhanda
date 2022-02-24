#ifndef _DHANDA_TXN_H_
#define _DHANDA_TXN_H_

#include <dhanda/dhanda.h>

typedef struct txn {
	int id;
	int amount;
	time_t cat;
	int type;
	char desc[256];
	int party_id;
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

/* Handy functions for passing data from Data layer to UI layer, since
 * UI functions only takes one argument and are called using callback
 * there is no way to call a callback with different type/number of
 * argument at run time. */
void txn_insert_in_list(dhanda *app, txn *p);
txn *txn_first_in_list(dhanda *app);
txn *txn_second_in_list(dhanda *app);

#endif

