#include<dhanda/dhanda.h>
#include<dhanda/txn.h>

int txn_add(dhanda *app, txn *txn)
{
	int init_posn, fin_posn;

	fseek(app->txn_fp, 0, SEEK_END);
	init_posn = ftell(app->txn_fp);
	fwrite(txn, sizeof(txn), 1, app->txn_fp);
	fin_posn = ftell(app->txn_fp);

	if (init_posn < fin_posn)
		return 0;
	else
		return -1;
}