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
	ptr = ptr->app->party_list->head;
	while(!ptr){
		p = (party *) ptr->data;
	printf("PARTY......\n\n");
	printf("ID   NAME                 TXN        DEBIT      CREDIT     ");
	printf("%-5d %-20s %-10d %-10d %-10d", p->id, p->name, p->amount, p->type);
	ptr = ptr->next;
}

