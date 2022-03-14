#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>


void ui_party_create(struct dhanda *app)
{
	/*long int phone = 9748538411,
		amount = 10000;
	char fname[64] = "Safwan", lname[64] = "Haider";
	*/
	party p;

	printf("CREATE....\n\n");
	printf("FIRST NAME :  ");
	get_string(p.fname, sizeof(p.fname));
	printf("LAST NAME  :  ");
	get_string(p.lname, sizeof(p.lname));

	printf("PHONE      :  ");
	get_string(p.phone, sizeof(p.phone));

	printf("AMOUNT     :  ");
	scanf("%d", &p.amount);

	party_insert_in_list(app, &p);

	puts("");
}

