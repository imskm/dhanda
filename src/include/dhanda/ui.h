#ifndef _DHANDA_UI_H_
#define _DHANDA_UI_H_

#include <dhanda/dhanda.h>

void ui_home(struct dhanda *app);
void ui_party_list(struct dhanda *app);
void ui_party_show(struct dhanda *app);
void ui_party_create(struct dhanda *app);
void ui_party_edit(struct dhanda *app);

void ui_txn_list(struct dhanda *app);
void ui_txn_show(struct dhanda *app);
void ui_txn_create(struct dhanda *app);

#endif
