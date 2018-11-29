#ifndef VECTOR_PRODUCT_H

#define VECTOR_PRODUCT_H

#include <stdint.h>
#include <x86intrin.h>

extern int64_t vector_product_naive(size_t length, int32_t *vector);

extern int64_t vector_product_vectorized(size_t length, int32_t *vector);

#endif