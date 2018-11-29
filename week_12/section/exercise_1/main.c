#include <stdint.h>
#include <stdio.h>
#include "vector-product.h"

static size_t vector_length = 8;

int main(int argc, char **argv) {
	int32_t vector[vector_length];
	int64_t product;

	for (size_t i = 0; i < vector_length; ++i) vector[i] = i + 1;

	printf("products of the vector:\n");
	for (size_t i = 0; i < vector_length; ++i) printf("%d ", vector[i]);
	putchar('\n');

	product = vector_product_naive(vector_length, vector);
	printf("sequential: %ld\n", product);

	product = vector_product_vectorized(vector_length, vector);
	printf("vector extensions: %ld\n", product);
}