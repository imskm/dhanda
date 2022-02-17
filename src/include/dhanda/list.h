#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


struct Node {
	void *data;
	struct Node *next;
};

typedef struct Node Node;

struct list {
	Node *head;
	int dsize; /* Data size */
	int count;
};

typedef struct list List;

List *list_create(int dsize);
Node *list_new_node(List *list, void *data);
void list_insert_end(List *list, Node *node);
void list_print(List *list);

/* @TODO */
Node *list_delete_front(Node *head);
Node *list_insert_front(Node *head, Node *node);




#endif

