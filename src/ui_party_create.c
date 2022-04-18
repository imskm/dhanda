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
	int len;
	long ret;
	char s[100];
	char *ptr;


	sky();
	bold();
	centreprint("DHANDA > PARTY > CREATE");
	printf("\n\n");
	reset();
	grey();
	printf("   FIRST NAME :  ");
	get_string(p.fname, sizeof(p.fname));
	printf("\n");
	printf("   LAST NAME  :  ");
	get_string(p.lname, sizeof(p.lname));
	printf("\n");
	printf("   PHONE      :  ");
	get_string(p.phone, sizeof(p.phone));
	
	printf("\n");
	printf("  AMOUNT     :  ");
    get_string(p.phone, sizeof(p.phone));
		
	reset();
	party_insert_in_list(app, &p);

	puts("");
}

