#include <dhanda/dhanda.h>
#include <dhanda/txn.h>
#include <dhanda/ui.h>


void ui_txn_create(struct dhanda *app)
{
	txn t;
	char line[256], ch;
	int len;
	debug_print("");

	printf("DHANDA > TRANSACTION > CREATE\n\n");
	printf("ID 				:		");
	scanf("%d", &t.id);
	printf("AMOUNT				:		");
	scanf("%d", &t.amount);
	printf("TYPE [O FOR CRED, 1 FOR DEBT]	:		");
	scanf("%d", &t.type);
	scanf("%c", &ch);
	printf("DESC				:		");
	get_line(t.desc, 256);
	/*if(len > 0)
		strcpy(t.desc, line);*/
	//scanf("%s", t.desc);
	printf("PARTY ID			:		");
	scanf("%d", &t.party_id);
	t.cat = time(NULL);
	txn_insert_in_list(app, &t);
	puts("");
}
