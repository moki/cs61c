#include "dgemm.h"
#include <stdio.h>

#define D (4)

static void _generate_quad_random_matrix(double *dst, size_t n);
static void _matrix_display(double *m, size_t n, char *name);
static void _matrix_clean(double *m, size_t n);

int main(int argc, char **argv) {
	double a[16] __attribute__ ((aligned (32))) = {
		1.0, 2.0, 3.0, 4.0,
		5.0, 6.0, 7.0, 8.0,
		9.0, 10.0, 11.0, 12.0,
		13.0, 14.0, 15.0, 16.0
	};

	double b[16] __attribute__ ((aligned (32))) = {
		11.0, 12.0, 13.0, 14.0,
		15.0, 16.0, 17.0, 18.0,
		19.0, 20.0, 21.0, 22.0,
		23.0, 24.0, 25.0, 26.0
	};

	double c[16] __attribute__ ((aligned (32))) = {
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0
	};

	_matrix_display(a, D, "A");
	_matrix_display(b, D, "B");

	scalar_dgemm(a, b, c, D);

	printf("A * B\t| scalar |\n\n");

	_matrix_display(c, D, "C");

	_matrix_clean(c, D);

	avx_dgemm(a, b, c, D);

	printf("A * B\t| avx |\n\n");

	_matrix_display(c, D, "C");

	double _a[256] __attribute__ ((aligned (32)));
	double _b[256] __attribute__ ((aligned (32)));
	double _c[256] __attribute__ ((aligned (32)));

	_generate_quad_random_matrix(_a, 16);
	_generate_quad_random_matrix(_b, 16);

	_matrix_clean(_c, 16);

	avx_unroll_dgemm(_a, _b, _c, 16);

	printf("A * B\t| avx unrolled |\n\n");

	_matrix_display(_c, 16, "C");

	_matrix_clean(_c, 16);

	avx_unroll_blocked_dgemm(_a, _b, _c, 16);

	printf("A * B\t| avx blocked unrolled |\n\n");

	_matrix_display(_c, 16, "C");

	return 0;
}

static void _generate_quad_random_matrix(double *dst, size_t n) {
	// todo: actual random
	for (size_t i = 0; i < n*n; ++i)
		dst[i] = (double) i * 1.0;
}

static void _matrix_display(double *m, size_t n, char *name) {
	printf("matrix %s\n\n", name);

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j)
			printf("%9.3f\t", m[i+j*n]);

		putchar('\n');
	}

	putchar('\n');
}

static void _matrix_clean(double *m, size_t n) {
	for (size_t i = 0; i < n*n; ++i)
		m[i] = 0.0;
}