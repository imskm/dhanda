#ifndef _DHANDA_PARTY_H_
#define _DHANDA_PARTY_H_

int dhanda_party_init(char *dbfilepath);
int dhanda_party_add(struct party *party);
int dhanda_party_update(struct party *party);
int dhanda_party_delete(struct party *party);
int dhanda_party_findbyid(int id, struct party *party);
int dhanda_party_search(char *query, struct dhanda_list *list);
int dhanda_party_get(struct dhanda_list *list, int items, int page);

#endif
