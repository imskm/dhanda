#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>


void ui_party_show(struct dhanda *app)
{
	int id;
	party *p;
	char fname[32];
	char lname[32];
	char phone[12];
	int amount;

	debug_print("");
	p = party_first_in_list(app);
	printf("ID    : %d\n\n", p->id);

	printf("FNAME :%s", p->fname);
	printf("\n\n");
	printf("LNAME :%s", p->lname);
	printf("\n\n");

	printf("PHONE : %s\n\n", p->phone);

	
}
