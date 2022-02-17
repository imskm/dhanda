#ifndef _DHANDA_PARTY_H_
#define _DHANDA_PARTY_H_

#include <dhanda/dhanda.h>

int dhanda_party_init(struct dhanda *app);
int dhanda_party_add(struct dhanda *app, struct party *party);
int dhanda_party_update(struct dhanda *app, struct party *party);
int dhanda_party_delete(struct dhanda *app, struct party *party);
int dhanda_party_findbyid(struct dhanda *app, int id, struct party *result);
int dhanda_party_search(struct dhanda *app, char *query, struct dhanda_list *list);
int dhanda_party_get(struct dhanda *app, struct dhanda_list *list, int items, int page);

#endif
