#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/* ***DON'T MODIFY THIS FILE! ONLY MODIFY COMMON.H!*** */

int main(int argc, char* argv[]) {
	printf("Let's generate a randomized array.\n");
	unsigned int vals[NUM_ELEMS];
	for(unsigned int i = 0; i < NUM_ELEMS; i++) vals[i] = rand() % 256;

	printf("Now let's sort it.\n");
	qsort(vals, NUM_ELEMS, sizeof(int), int_comparator);

	printf("Starting sorted sum.\n");
	printf("Sum: %lld\n", sum(vals));

	printf("Starting sorted unrolled sum.\n");
	printf("Sum: %lld\n", sum_unrolled(vals));

	printf("Starting sorted SIMD sum.\n");
	printf("Sum: %lld\n", sum_simd(vals));

	printf("Starting sorted SIMD unrolled sum.\n");
	printf("Sum: %lld\n", sum_simd_unrolled(vals));
}
