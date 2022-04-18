#include <dhanda/dhanda.h>
#include <dhanda/txn.h>
#include <dhanda/ui.h>


void ui_txn_show(struct dhanda *app)
{
	Node *ptr;
	ptr = app->txn_list->head;
	txn *t;
	debug_print("");

	t = (txn *) ptr->data;

	sky();
	bold();
	centreprint("DHANDA > TRANSACTION > SHOW");
	printf("\n\n");
	reset();
	printf("%-10s %-10s %-10s %-10s %-10s %-10s", "ID", 
												  "AMOUNT",
												  "CAT",
												  "TYPE",
												  "PARTY_ID",
												  "DESC");
	printf("\n\n");
	
	printf("%-10d %-10d %-10ld %-10d %-10d %s\n\n", t->id, 
										  t->amount, 
										  t->cat, 
										  t->type,
										  t->party_id,
										  t->desc);
		
	

	  /*printf("PARTY TRANSACTION......\n\n");
		printf("NAME       TXN        DEBIT      CREDIT     ");
		printf("\n\n");
		printf("\n\n");
		printf("%-10d %-10d %-10d %-10d", id2, txn2, debit2, credit2);
		printf("\n\n");
		printf("%-10d %-10d %-10d %-10d", id3, txn3, debit3, credit3);
			puts("");*/

}

