#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>


void ui_party_show(struct dhanda *app)
{
	char name[64] = "Safwan", addrr[64] = "Kankinara";
	long int phone = 9748538411;
	int year = 2010;

	printf("PARTY :------%s", name);
	printf("\n\n");
	printf("PHONE : %ld\n\n", phone);
	printf("PLACE : %s\n\n", addrr);
	printf("Joined \n");
	printf(" Year : %d\n\n", year);
	puts("");

}
