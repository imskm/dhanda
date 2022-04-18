#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>

void ui_party_list(struct dhanda *app)
{
	Node *ptr;
	party *p;
	ptr = app->party_list->head;
	/*printf("\x1b[30;106m  \x1b[1m \x1b[3m DHANDA > PARTY > LIST                    \n\n");
	printf("\x1b[0m");*/
	sky();
	bold();
	centreprint("DHANDA > PARTY > LIST");
	printf("\n\n");
	reset();
	grey();

	printf("   %-13s %-20s %-20s %-15s %-10s\n\n\n", "ID", "FIRST NAME", "LAST NAME", "AMOUNT", "PHONE");
	reset();
	while(ptr){
		p = (party *) ptr->data;
		printf("   %-13d %-20s %-20s %-15d %-10s\n\n", p->id, p->fname, p->lname, p->amount, p->phone);
		ptr = ptr->next;
	}
}

