#include "vector-product.h"

int64_t vector_product_naive(size_t length, int32_t *vector) {
	int64_t product;
	size_t i;

	for (i = 0, product = 1; i < length; ++i) {
		product *= vector[i];
	}

	return product;
}

int64_t vector_product_vectorized(size_t length, int32_t *vector) {
	__m128i product = _mm_set1_epi32(1);
	int32_t last[4];
	size_t i;

	for (i = 0; i < length / 16; i += 4) {
		product = _mm_mullo_epi32(
			product,
			_mm_loadu_si128((__m128i *) (vector + i))
		);
	}

	_mm_storeu_si128((__m128i *) last, product);

	for (i = length/16; i < length; ++i) last[0] *= vector[i];

	for (i = 1; i < 4; ++i) last[0] *= last[i];

	return last[0];
}