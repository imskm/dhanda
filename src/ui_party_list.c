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
	printf("PARTY......\n\n");
	printf("ID   NAME                 AMOUNT");
	while(!ptr){
		p = (party *) ptr->data;
		printf("%-5d %-20s %-10d ", p->id, p->fname, p->amount);
		ptr = ptr->next;
	}
}

