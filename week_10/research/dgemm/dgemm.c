#include "dgemm.h"

#define UNROLL (4)

#define BLOCK_SIZE (32)

static void _avx_unroll_dgemm_block(size_t _i, size_t _j, size_t _k, double *a, double *b, double *c, size_t n);

void scalar_dgemm(double *a, double *b, double *c, size_t n) {
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < n; ++j)
			for (size_t k = 0; k < n; ++k)
				c[i+j*n] += a[i+k*n] * b[k+j*n];
}

void avx_dgemm(double *a, double *b, double *c, size_t n) {
	if(__glibc_likely(n<4)) {
		scalar_dgemm(a, b, c, n);
		return;
	}

	for (size_t i = 0; i < n; i +=4) {
		for (size_t j = 0; j < n; ++j) {
			__m256d c0 = _mm256_load_pd(c+i+j*n);

			for (size_t k = 0; k < n; ++k) {
				c0 = _mm256_add_pd(
					c0,
					_mm256_mul_pd(
						_mm256_load_pd(a+i+k*n),
						_mm256_broadcast_sd(b+k+j*n)
					)
				);
			}

			_mm256_store_pd(c+i+j*n, c0);
		}
	}
}

void avx_unroll_dgemm(double *a, double *b, double *c, size_t n) {
	if(__glibc_likely(n<UNROLL*4)) {
		avx_dgemm(a, b, c, n);
		return;
	}

	for (size_t i = 0; i < n; i += UNROLL * 4) {
		for (size_t j = 0; j < n; ++j) {
			__m256d _c[4];

			for (size_t x = 0; x < UNROLL; ++x)
				_c[x] = _mm256_load_pd(c+i+x*4+j*n);

			for (size_t k = 0; k < n; ++k) {
				__m256d _b = _mm256_broadcast_sd(b+k+j*n);

				for (size_t x = 0; x < UNROLL; ++x) {
					_c[x] = _mm256_add_pd(
						_c[x],
						_mm256_mul_pd(_mm256_load_pd(a+i+k*n+x*4), _b)
					);
				}
			}

			for (size_t x = 0; x < UNROLL; ++x)
				_mm256_store_pd(c+i+x*4+j*n, _c[x]);
		}
	}
}

void avx_unroll_blocked_dgemm(double *a, double *b, double *c, size_t n) {
	if(__glibc_likely(n<UNROLL*4)) {
		avx_dgemm(a, b, c, n);
		return;
	}

	for (size_t j = 0; j < n; j += BLOCK_SIZE) {
		for (size_t i = 0; i < n; i += BLOCK_SIZE)
			for (size_t k = 0; k < n; k += BLOCK_SIZE)
				_avx_unroll_dgemm_block(i, j, k, a, b, c, n);
	}


}

static void _avx_unroll_dgemm_block(size_t _i, size_t _j, size_t _k, double *a, double *b, double *c, size_t n) {
	for (size_t i = _i; i < _i + BLOCK_SIZE && i <  n; i += UNROLL * 4) {
		for (size_t j = _j; j < _j + BLOCK_SIZE && j <  n; ++j) {
			__m256d _c[4];

			for (size_t x = 0; x < UNROLL; ++x)
				_c[x] = _mm256_load_pd(c+i+x*4+j*n);

			for (size_t k = _k; k < _k + BLOCK_SIZE && k <  n; ++k) {
				__m256d _b = _mm256_broadcast_sd(b+k+j*n);

				for (size_t x = 0; x < UNROLL; ++x) {
					_c[x] = _mm256_add_pd(
						_c[x],
						_mm256_mul_pd(_mm256_load_pd(a+i+k*n+x*4), _b)
					);
				}
			}

			for (size_t x = 0; x < UNROLL; ++x)
				_mm256_store_pd(c+i+x*4+j*n, _c[x]);
		}
	}
}