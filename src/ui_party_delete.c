#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>



void ui_party_delete(struct dhanda *app)
{
	Node *ptr;
	party *p;

	debug_print("");


	sky();
	bold();
	centreprint("DHANDA > PARTY > DELETE");
	printf("\n\n");
	reset();

	
	ptr = app->party_list->head;
	while(!ptr){
		p = (party *) ptr->data;
	}

}
