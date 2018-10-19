#include "int-linked-list.h"

static void _free(void *ptr);

struct int_linked_list {
	ill_t *next;
	int entry;
};


ill_t *ill_constructor(void) {
	ill_t *list = malloc(sizeof(*list));
	if (!list) return NULL;

	list->next = NULL;

	return list;
}

void ill_insert_front(ill_t *list, int entry) {
	ill_t *new_node = malloc(sizeof(*new_node));
	if (!new_node) exit(EXIT_FAILURE);

	new_node->entry = entry;
	new_node->next = list->next;

	list->next = new_node;
}

int ill_delete_front(ill_t *list) {
	if (!list) exit(EXIT_FAILURE);
	int v;

	ill_t *doomed = list->next;
	if (!doomed) exit(EXIT_FAILURE);

	list->next = doomed->next;

	v = doomed->entry;
	_free(doomed);

	return v;
}

void ill_destructor(ill_t *list) {
	ill_t *cursor = list;

	while (cursor) {
		cursor = list->next;
		_free(list);
		list = cursor;
	}
}

static void _free(void *ptr) {
	free(ptr);

	ptr = NULL;
}

unsigned char ill_is_empty(ill_t *list) {
	return !list->next;
}