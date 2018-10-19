#ifndef INT_LINKED_LIST_H
#define INT_LINKED_LIST_H

#include <stdlib.h>

typedef struct int_linked_list ill_t;

ill_t *ill_constructor(void);

void ill_insert_front(ill_t *list, int entry);

int ill_delete_front(ill_t *list);

void ill_destructor(ill_t *list);

unsigned char ill_is_empty(ill_t *list);

#endif