#ifndef _DHANDA_PARTY_H_
#define _DHANDA_PARTY_H_

#include <dhanda/dhanda.h>

typedef struct party {
	// @TODO
} party;

typedef struct party_filter {
	int page;
	int items;
	// @TODO
} party_filter;


int party_init(dhanda *app);
int party_add(dhanda *app, party *party);
int party_update(dhanda *app, party *old_party, struct party *new_party);
int party_delete(dhanda *app, party *party);
int party_findbyid(dhanda *app, int id, party *result);
int party_search(dhanda *app, char *query, struct list *result);
int party_get(dhanda *app, party_filter filter, struct list *result);

#endif
