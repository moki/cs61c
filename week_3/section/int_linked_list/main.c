#include "int-linked-list.h"
#include <stdio.h>

int main(int argc, char **argv) {
	int i;

	ill_t *list = ill_constructor();
	if (!list) exit(EXIT_FAILURE);

	// insert 10 elements into list
	for (i = 0; i < 10; i++)
		ill_insert_front(list, i);

	// delete/pop while not empty
	while (!ill_is_empty(list))
		printf("%d ", ill_delete_front(list));

	putchar('\n');

	ill_destructor(list);

	list = ill_constructor();
	if (!list) exit(EXIT_FAILURE);

	// insert 10 elements into list
	for (i = 0; i < 30; i++)
		ill_insert_front(list, i);

	ill_destructor(list);

	return 0;
}