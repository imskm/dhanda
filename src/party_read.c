#include <dhanda/dhanda.h>
#include <dhanda/party.h>




int party_findbyid(dhanda *app, int id, party *result)
{
	int matched = 0;
	
	while(fread(result, sizeof(party), 1, app->party_fp) > 0) {
		if(id == result->id) {
			matched = 1;
			break;
		}
	}
	if(matched == 0) {
		if(ferror(app->party_fp))
			matched = -1;
		
		else
			matched = 0;
	}
		
	return matched;
}


int party_search(dhanda *app, char *query, struct list *result)
{
	party temp;
	Node *node;
	int matched = 0;
	
	
	while(fread(&temp, sizeof(temp), 1, app->party_fp) > 0) {
		if(strstr(temp.phone, query)) {
			matched = 1;
			node = list_new_node(result, (void *) &temp);
			list_insert_end(result, node);
		}
		
		if(!node)
			break;
	}
	return matched;
	
}
			

int party_get(dhanda *app, party_filter filter, struct list *result)
{
	List *list;
	party temp;
	int count = 0, offset;
	Node *node;
	
	/*offset = (filter.page - 1) * filter.items * sizeof(party);
	fseek(app->party_fp, offset * -1, SEEK_END);*/
	
	fseek(app->party_fp, 0, SEEK_SET);
	while(fread(&temp, sizeof(temp), 1, app->party_fp) > 0) {
		if(count >= filter.items)
			break;
			
		node = list_new_node(result, (void *) &temp);
		list_insert_end(result, node);
		count++;
		
		if(!node) 
			break;
	}
	
	return count;
}
		

		














	
	
	
