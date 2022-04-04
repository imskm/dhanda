#include <dhanda/dhanda.h>
#include <dhanda/txn.h>

int txn_findbyid(dhanda *app, int id, txn *result)
{
	int matched = 0;

	debug_print("");

	fseek(app->txn_fp, 0, SEEK_SET);
	while(fread(result, sizeof(txn), 1, app->txn_fp) > 0) {
		if(id == result->id) {
			matched = 1;
			break;
		}
	}
	if(matched == 0) {
		if(ferror(app->txn_fp))
			matched = -1;
		
		else
			matched = 0;
	}
	return matched;


}


	
int txn_search(dhanda *app, char *query, struct list *result)
{
	Node *n;
	txn temp;
	int matched = 0;
	debug_print("");
	int party_id = atoi(query);
	
	fseek(app->txn_fp, 0, SEEK_SET);
	while(fread(&temp, sizeof(temp), 1, app->txn_fp) > 0) {
		if (party_id == temp.party_id) {
			n = list_new_node(result, &temp);
			list_insert_end(result, n);
			++matched;
		}
		/* @TODO */
		/*
		if (strcmp(temp.cat, query) == 0) {
			matched = 0;
			break;
		}
		*/
	}

	return matched;
}

int txn_findbytype(dhanda *app, int type, struct list *result)
{	
	txn temp;
	int count;
	Node *n;

	count = 0;
	debug_print("");
	while(fread(&temp, sizeof(txn), 1, app->txn_fp)>0) {

		if (type == temp.type)
		{
			n = list_new_node(result, &temp);
			list_insert_end(result, n);
			count++;
		}
	}

	return count;
}

int txn_get(dhanda *app, txn_filter filter, struct list *result)
{
	txn temp;
	Node *node;
	int count, offset;
	debug_print("");

	count = 0;
	// offset = (filter.page - 1) * filter.items * sizeof(txn);
	// fseek(app->txn_fp, -offset, SEEK_END);

	fseek(app->txn_fp, 0, SEEK_SET);
	while (fread(&temp, sizeof(temp), 1, app->txn_fp) > 0) {
		if (count >= filter.items)
			break;

		node = list_new_node(result, (void *) &temp);
		if (node == NULL)
			break;
		list_insert_end(result, node);
	}

	return count;
}
