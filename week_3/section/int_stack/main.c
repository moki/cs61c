#include "int-stack.h"

#include <stdio.h>

int main(int argc, char **argv) {
	int i;
	printf("int stack hello\n");

	int_stack_t *stack = int_stack_constructor();

	// push 10 elements
	for (i = 0; i < 10; i++)
		int_stack_push(stack, i);

	// pop 10 elements
	for (i = 0; i < 10; i++)
		printf("%d ", int_stack_pop(stack));

	putchar('\n');

	int_stack_destructor(stack);
}