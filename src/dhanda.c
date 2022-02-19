#include <stdio.h>

#include <dhanda/dhanda.h>
#include <dhanda/ui.h>
#include <dhanda/party.h>
#include <dhanda/txn.h>

int main(int argc, char *argv[])
{
	struct dhanda app = {};

	dhanda_init_app(&app);

	ui_home(&app);
	//ui_party_list(&app);
	//ui_party_show(&app);
	//ui_party_create(&app);
	//ui_party_edit(&app);

	return 0;
}

void
dhanda_init_app(struct dhanda *app)
{
}
