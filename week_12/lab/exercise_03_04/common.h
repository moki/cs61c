#ifndef COMMON_H
#define COMMON_H

#include <x86intrin.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>

#define NUM_ELEMS ((1 << 16) + 10)
#define OUTER_ITERATIONS (1 << 16)

long long int sum(unsigned int vals[NUM_ELEMS]) {
	clock_t start = clock();

	long long int sum = 0;
	for(unsigned int w = 0; w < OUTER_ITERATIONS; w++) {
		for(unsigned int i = 0; i < NUM_ELEMS; i++) {
			if(vals[i] >= 128) {
				sum += vals[i];
			}
		}
	}
	clock_t end = clock();
	printf("Time taken: %Lf s\n", (long double)(end - start) / CLOCKS_PER_SEC);
	return sum;
}

long long int sum_unrolled(unsigned int vals[NUM_ELEMS]) {
	clock_t start = clock();
	long long int sum = 0;

	for(unsigned int w = 0; w < OUTER_ITERATIONS; w++) {
		for(unsigned int i = 0; i < NUM_ELEMS / 4 * 4; i += 4) {
			if(vals[i] >= 128) sum += vals[i];
			if(vals[i + 1] >= 128) sum += vals[i + 1];
			if(vals[i + 2] >= 128) sum += vals[i + 2];
			if(vals[i + 3] >= 128) sum += vals[i + 3];
		}

		//This is what we call the TAIL CASE
		//For when NUM_ELEMS isn't a multiple of 4
		//NONTRIVIAL FACT: NUM_ELEMS / 4 * 4 is the largest multiple of 4 less than NUM_ELEMS
		for(unsigned int i = NUM_ELEMS / 4 * 4; i < NUM_ELEMS; i++) {
			if (vals[i] >= 128) {
				sum += vals[i];
			}
		}
	}
	clock_t end = clock();
	printf("Time taken: %Lf s\n", (long double)(end - start) / CLOCKS_PER_SEC);
	return sum;
}

long long int sum_simd(unsigned int vals[NUM_ELEMS]) {
	// for(size_t i = 0; i < NUM_ELEMS; ++i) printf("vals[%d]:%d\n", i, vals[i]);
	clock_t start = clock();
	__m128i _127 = _mm_set1_epi32(127);
	long long int result = 0;

	for(unsigned int w = 0; w < OUTER_ITERATIONS; w++) {
		__m128i _result = _mm_set1_epi32(0);
		int32_t last[4];

		for(unsigned int i = 0; i+4 <= NUM_ELEMS; i+=4) {
			__m128i next_four = _mm_loadu_si128((__m128i *) (vals + i));
			__m128i mask_four = _mm_cmpgt_epi32(next_four, _127);

			__m128i masked_four = _mm_and_si128(next_four, mask_four);

			_result = _mm_add_epi32(_result, masked_four);
		}

		size_t tail_index = NUM_ELEMS - (NUM_ELEMS % 4);

		_mm_storeu_si128((__m128i *) last, _result);

		for (; tail_index < NUM_ELEMS; ++tail_index)
			last[0] += vals[tail_index] > 127 ? vals[tail_index] : 0;

		for (tail_index = 1; tail_index < 4; ++tail_index) last[0] += last[tail_index];

		result += last[0];

	}

	clock_t end = clock();
	printf("Time taken: %Lf s\n", (long double)(end - start) / CLOCKS_PER_SEC);
	return result;
}

long long int sum_simd_unrolled(unsigned int vals[NUM_ELEMS]) {
	if (NUM_ELEMS < 16)
		return sum_simd(vals);

	clock_t start = clock();
	__m128i _127 = _mm_set1_epi32(127);
	long long int result = 0;

	for(unsigned int w = 0; w < OUTER_ITERATIONS; w++) {
		__m128i _result = _mm_set1_epi32(0);
		int32_t last[4];

		for(unsigned int i = 0; i+4*4 <= NUM_ELEMS; i+=4*4) {
			__m128i next_four;
			__m128i mask_four;
			__m128i masked_four;

			// [i:i+3]
			next_four = _mm_loadu_si128((__m128i *) (vals + i));
			mask_four = _mm_cmpgt_epi32(next_four, _127);

			masked_four = _mm_and_si128(next_four, mask_four);

			_result = _mm_add_epi32(_result, masked_four);

			// [i+4:i+7]
			next_four = _mm_loadu_si128((__m128i *) (vals + i + 4));
			mask_four = _mm_cmpgt_epi32(next_four, _127);

			masked_four = _mm_and_si128(next_four, mask_four);

			_result = _mm_add_epi32(_result, masked_four);

			// [i+8:i+11]
			next_four = _mm_loadu_si128((__m128i *) (vals + i + 8));
			mask_four = _mm_cmpgt_epi32(next_four, _127);

			masked_four = _mm_and_si128(next_four, mask_four);

			_result = _mm_add_epi32(_result, masked_four);

			// [i+12:i+15]
			next_four = _mm_loadu_si128((__m128i *) (vals + i + 12));
			mask_four = _mm_cmpgt_epi32(next_four, _127);

			masked_four = _mm_and_si128(next_four, mask_four);

			_result = _mm_add_epi32(_result, masked_four);

		}

		size_t tail_index = NUM_ELEMS - (NUM_ELEMS % 16);

		_mm_storeu_si128((__m128i *) last, _result);

		for (; tail_index < NUM_ELEMS; ++tail_index)
			last[0] += vals[tail_index] > 127 ? vals[tail_index] : 0;

		for (tail_index = 1; tail_index < 4; ++tail_index) last[0] += last[tail_index];

		result += last[0];

	}

	clock_t end = clock();
	printf("Time taken: %Lf s\n", (long double)(end - start) / CLOCKS_PER_SEC);
	return result;
}

/* DON'T TOUCH THIS FUNCTION */
int int_comparator(const void* a, const void* b) {
	if(*(unsigned int*)a == *(unsigned int*)b) return 0;
	else if(*(unsigned int*)a < *(unsigned int*)b) return -1;
	else return 1;
}

#endif
