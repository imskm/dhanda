#include <stdio.h>

#include <dhanda/dhanda.h>

int main(int argc, char *argv[])
{
	struct dhanda app = {};

	dhanda_init_app(&app);

	dhanda_ui_home(&app);
	//dhanda_ui_party_list(&app);
	//dhanda_ui_party_show(&app);
	//dhanda_ui_party_create(&app);
	//dhanda_ui_party_edit(&app);

	return 0;
}

void
dhanda_init_app(struct dhanda *app)
{
}
