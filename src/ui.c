#include <dhanda/dhanda.h>
#include <dhanda/ui.h>

void
ui_home(dhanda *app)
{
	ui_party_list(app);
	return;
	int txn = 567,
		amount = 12399,
		party = 56,
		debit = 144,
		credit = 12;

	printf("DHANDA\n\n");
	printf("Total # txn     Total amount   Total # party    Total debit     Total credit");
	printf("\n");
	printf("___________     ____________   _____________    ___________     ____________");
	printf("\n\n");
	printf("%-15d %-15d %-15d %-15d %-15d ", txn, amount, party, debit, credit);
	printf("\n\n");
	puts("");


}


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
void ui_party_edit(struct dhanda *app)
{
	long int phone, amount;
	char fname[64], lname[64];
	printf("EDIT....\n\n");
	printf("FIRST NAME :  %s\n\n", fname);
	printf("LAST NAME  :  %s\n\n", lname);
	printf("PHONE      :  %ld\n\n", phone);
	printf("AMOUNT     :  %ld\n\n", amount);
	puts("");
}

void ui_txn_list(struct dhanda *app);


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