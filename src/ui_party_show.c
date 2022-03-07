#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>


void ui_party_show(struct dhanda *app)
{
	int id;
	char fname[32];
	char lname[32];
	char phone[12];
	int amount;
	ptr = ptr->app->party_list->head;
	while(!ptr){
		p = (party *) ptr->data;
		printf("PARTY :------%s", p->fname);
		printf("\n\n");
		printf("PHONE : %ld\n\n", p->phone);
		
		printf(" ID : %d\n\n", p->id);

	}



}
