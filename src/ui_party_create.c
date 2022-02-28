#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>


void ui_party_create(struct dhanda *app)
{
	/*long int phone = 9748538411,
		amount = 10000;
	char fname[64] = "Safwan", lname[64] = "Haider";
	*/

	struct party_create {
		char fname[64];
		char lname[64];
		long int phone,amount;

	}
	
	printf("CREATE....\n\n");
	printf("FIRST NAME :  ");
	scanf("%s", );
	printf("LAST NAME  :  ");
	scanf("%s", );

	printf("PHONE      :  ");
	scanf("%ld");

	printf("AMOUNT     :  ");
	scanf("%ld");

	puts("");
}

