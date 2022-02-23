#include <dhanda/dhanda.h>
#include <dhanda/txn.h>
#include <dhanda/ui.h>


void ui_txn_create(struct dhanda *app)
{
	char name[64] = "Safwan";
	int debit = 1000, credit = 0;

	printf("TRANSACTION - CREATE\n\n");
	printf("NAME     :  %s\n\n", name);
	printf("DEBITED  :  %d\n\n", debit);
	printf("CREDITED :  %d\n\n", credit);
	puts("");
}

