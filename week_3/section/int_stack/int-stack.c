#include "int-stack.h"

static void stack_expand(int_stack_t *stack);
static void stack_shrink(int_stack_t *stack);
static void _free(void *ptr);

struct int_stack {
	int 	*data;
	uint32_t size;
	uint32_t used;
};

int_stack_t *int_stack_constructor() {
	int_stack_t *stack = malloc(sizeof(*stack));
	if (!stack) return NULL;

	stack->size = stack->used = 0;

	stack->data = NULL;

	return stack;
}

void int_stack_push(int_stack_t *stack, int entry) {
	if (stack->used >= stack->size)
		stack_expand(stack);

	stack->data[stack->used++] = entry;
}

int int_stack_pop(int_stack_t *stack) {
	if (!stack->used) return 0;

	if (stack->used << 1 == stack->size)
		stack_shrink(stack);

	return stack->data[--stack->used];
}

void int_stack_destructor(int_stack_t *stack) {
	if (!stack) return;

	if (stack->data)
		_free(stack->data);

	_free(stack);
}

static void stack_expand(int_stack_t *stack) {
	if (!stack->size) {
		stack->size = 1;
		stack->data = malloc(stack->size * sizeof(int));
		if (!stack->data) exit(EXIT_FAILURE);
		return;
	}

	stack->size <<= 1;
	stack->data = realloc(stack->data, sizeof(int) * stack->size);
	if (!stack->data) exit(EXIT_FAILURE);
}

static void stack_shrink(int_stack_t *stack) {
	stack->size >>= 1;
	stack->data = realloc(stack->data, sizeof(int) * stack->size);
	if (!stack->data) exit(EXIT_FAILURE);
}

static void _free(void *ptr) {
	free(ptr);
	ptr = NULL;
}