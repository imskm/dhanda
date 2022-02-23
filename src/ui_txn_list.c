#include <dhanda/dhanda.h>
#include <dhanda/txn.h>
#include <dhanda/ui.h>


void ui_txn_list(struct dhanda *app)
{
	char ptype1[32] = "CREDITED", ptype2[32] = "DEBITED";
	char name1[64] = "Safwan", name2[64] = "Habibi", name3[64] = "Iqra", name4[64] = "Hero";
	int id1 = 4, id2 = 3, id3 = 2, id4 = 1;
	int amount1 = 31231, amount2 = 34334, amount3 = 33324, amount4 = 4545;
	printf("TRANSACTION ----- HISTORY\n\n");

	printf("ID         NAME            AMOUNT          PTYPE\n");
	printf("__         ____            ______          _____");
	printf("\n\n");
	printf("%-10d %-15s %-15d %-15s\n\n", id1, name1, amount1, ptype2);
	printf("%-10d %-15s %-15d %-15s\n\n", id2, name2, amount2, ptype1);
	printf("%-10d %-15s %-15d %-15s\n\n", id3, name3, amount3, ptype2);
	printf("%-10d %-15s %-15d %-15s\n\n", id4, name4, amount4, ptype1);
}

