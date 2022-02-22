#include <dhanda/list.h>

List *list_create(int dsize)
{
	List *list;

	list = malloc(sizeof(*list));

	if (list) {
		list->head = NULL;
		list->dsize = dsize;
		list->count = 0;
	}

	return list;
}

Node *list_new_node(List *list, void *data)
{
	int ds = list->dsize;
	void *d;
	Node *node;

	d = malloc(ds);
	if (d) {
		memcpy(d, data, ds);
	}

	node = malloc(sizeof(*node));
	if (node) {
		node->data = d;
		node->next = NULL;
	}

	return node;
}

void list_insert_end(List *list, Node *node)
{
	Node *ptr;

	if (list->head == NULL) {
		list->head = node;
		return;
	}

	ptr = list->head;
	while (ptr->next) {
		ptr = ptr->next;
	}

	ptr->next = node;
}


