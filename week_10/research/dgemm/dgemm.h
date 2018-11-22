#ifndef DGEMM
#define DGEMM

#include <stddef.h>
#include <x86intrin.h>

extern void scalar_dgemm(double *a, double *b, double *c, size_t n);

extern void avx_dgemm(double *a, double *b, double *c, size_t n);

extern void avx_unroll_dgemm(double *a, double *b, double *c, size_t n);

void avx_unroll_blocked_dgemm(double *a, double *b, double *c, size_t n);

#endif