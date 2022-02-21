#include <dhanda/dhanda.h>
#include <dhanda/party.h>




int party_findbyid(dhanda *app, int id, party *result)
{
	int matched = -1;
	
	while(fread(result, sizeof(party), 1, app->party_fp) > 0) {
		if(id == result->id) {
			matched = 0;
			break;
		}
	}
	return matched;
}


int party_search(dhanda *app, char *query, struct list *result)
{
	party temp;
	int matched = -1;
	
	
	while(fread(&temp, sizeof(temp), 1, app->party_fp) > 0) {
		if(strcmp(temp.phone, query) == 0) {
			matched = 0;
			break;
		}
	}
	
	return matched;
}
			

int party_get(dhanda *app, party_filter filter, struct list *result)
{
	List *list;
	party temp;
	int count = 0, ds = list->dsize;
	Node *node;
	
	
	while(fread(&temp, sizeof(temp), 1, app->party_fp) > 0) {
		if(result->head == NULL) {
			list = list_create(ds);
			result->head = list_new_node(list, temp.fname);
			count++;
		}
		else {
			node = list_new_node(list, temp.fname);
			list_insert_end(list, node);
			count++;
		}
	}
	filter.items =  result->count = count;
	
	return count;
}	
		
	
			
		
		














	
	
	
