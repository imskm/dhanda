#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>

void ui_party_list(struct dhanda *app)
{
	Node *ptr;
	party *p;
	int id;
	int amount;
	time_t cat;
	int type;
	char desc[256];
	int party_id;
	ptr = app->party_list->head;
	printf("DHANDA > PARTY LIST\n\n");
	printf("%-5s %-20s %-20s %-15s %-10s", "ID", "FNAME", "LNAME", "AMOUNT", "PHONE");
	while(ptr){
		p = (party *) ptr->data;
		printf("%-5d %-20s %-20s %-15d %-10s", p->id, p->fname, p->lname, p->amount, p->phone);
		ptr = ptr->next;
	}
}

