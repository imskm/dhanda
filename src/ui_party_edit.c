#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>


void ui_party_edit(struct dhanda *app)
{
	long int phone, amount;
	char fname[64], lname[64];

	debug_print("");
	printf("DHANDA > PARTY > EDIT\n\n");
	printf("FIRST NAME :  %s\n\n", fname);
	printf("LAST NAME  :  %s\n\n", lname);
	printf("PHONE      :  %ld\n\n", phone);
	printf("AMOUNT     :  %ld\n\n", amount);
	puts("");
}


