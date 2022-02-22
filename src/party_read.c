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
	int count = 0, offset;
	Node *node;
	
	offset = (filter.page - 1) * filter.items * sizeof(party);
	fseek(app->party_fp, offset * -1, SEEK_END);
	while(fread(&temp, sizeof(temp), 1, app->party_fp) > 0) {
		if(count >= filter.items)
			break;
			
		node = list_new_node(result, (void *) &temp);
		list_inser_end(result, node);
		
		if(node == NULL) 
			break;
		list_insert_end(result, node);
	}
	
	return count;
}
		

		














	
	
	
