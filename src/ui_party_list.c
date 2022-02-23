#include <dhanda/dhanda.h>
#include <dhanda/party.h>
#include <dhanda/ui.h>

void ui_party_list(struct dhanda *app)
{
	char name1[64] = "Safwanhaider", name2[64] = "Rakesh", name3[64] = "Sonali";
	int txn1 = 1223, txn2 = 4234, txn3 = 2345;
	int debit1 = 52323, debit2 = 23432, debit3 = 23423;
	int credit1 = 122, credit2 = 23, credit3 = 2323;
	printf("PARTY......\n\n");
	printf("NAME                 TXN        DEBIT      CREDIT     ");
	printf("\n\n");
	printf("%-20s %-10d %-10d %-10d", name1, txn1, debit1, credit1);
	printf("\n\n");
	printf("%-20s %-10d %-10d %-10d", name2, txn2, debit2, credit2);
	printf("\n\n");
	printf("%-20s %-10d %-10d %-10d", name3, txn3, debit3, credit3);
	puts("");


}

