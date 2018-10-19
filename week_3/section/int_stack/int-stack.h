#ifndef INT_STACK_H
#define INT_STACK_H

#include <stdlib.h>
#include <stdint.h>

typedef struct int_stack int_stack_t;

int_stack_t *int_stack_constructor();

void int_stack_push(int_stack_t *stack, int entry);

int int_stack_pop(int_stack_t *stack);

void int_stack_destructor(int_stack_t *stack);

#endif