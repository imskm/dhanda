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

	list->count += 1;
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

void list_delete_front(List *list)
{
	Node *ptr;

	ptr = list->head;
	if (ptr == NULL)
		return;

	list->head = ptr->next;
	list->count -= 1;

	free(ptr->data);
	free(ptr);
}

void list_delete_all(List *list)
{
	while (list->head) {
		list_delete_front(list);
	}
}

