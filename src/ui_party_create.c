#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>


void ui_party_create(struct dhanda *app)
{
	long int phone = 9748538411,
		amount = 10000;
	char fname[64] = "Safwan", lname[64] = "Haider";


	printf("CREATE....\n\n");
	printf("FIRST NAME :  %s\n\n", fname);
	printf("LAST NAME  :  %s\n\n", lname);
	printf("PHONE      :  %ld\n\n", phone);
	printf("AMOUNT     :  %ld\n\n", amount);
	puts("");
}

