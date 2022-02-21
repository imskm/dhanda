#include<dhanda/dhanda.h>

int txn_findbyid(dhanda *app, int id, txn *result)
{
	int matched = -1;

	while(fread(result, sizeof(txn), 1, app->txn_fp) > 0) {
		if(id == result->id) {
			matched = 0;
			break;
		}
	}
	return matched;

}


	
int txn_search(dhanda *app, char *query, struct list *result)
{

	txn temp;
	int matched = -1;

	while(fread(&temp, sizeof(temp), 1, app->txn_fp) > 0) {
		if (strcmp(temp->cat, query) == 0)
		{
			matched = 0;
			break;
		}
	}
	return matched;

}

int txn_findbytype(dhanda *app, int type, struct list *result)
{	
	int matched = -1;

	while(fread(result, sizeof(txn), 1, app->txn_fp)>0){
		if (type == result->type)
		{
			matched = 0;
			break;
		}
	}
	return matched;
}

int txn_get(dhanda *app, txn_filter filter, struct list *result)
{
	
}
