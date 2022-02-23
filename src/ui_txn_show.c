#include <dhanda/dhanda.h>
#include <dhanda/txn.h>
#include <dhanda/ui.h>


void ui_txn_show(struct dhanda *app)
{
	int id1 = 3, id2 = 2, id3 = 1;
	int txn1 = 1223, txn2 = 4234, txn3 = 2345;
	int debit1 = 52323, debit2 = 23432, debit3 = 23423;
	int credit1 = 122, credit2 = 23, credit3 = 2323;
	printf("PARTY TRANSACTION......\n\n");
	printf("NAME       TXN        DEBIT      CREDIT     ");
	printf("\n\n");
	printf("%-10d %-10d %-10d %-10d", id1, txn1, debit1, credit1);
	printf("\n\n");
	printf("%-10d %-10d %-10d %-10d", id2, txn2, debit2, credit2);
	printf("\n\n");
	printf("%-10d %-10d %-10d %-10d", id3, txn3, debit3, credit3);
	puts("");

}

