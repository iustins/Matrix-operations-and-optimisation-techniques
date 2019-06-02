/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include<cblas.h>

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	
	int i,j;	
	double* C = calloc(N * N, sizeof(double));
	
        cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B, N, A, N, 0.0, C, N);
	
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, A, N, B, N, 1.0, C, N);
	
	for(i = 1; i < N; i++)
		for(j = 0; j < i; j++)
	       	      C[i * N + j] = 0;

	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, C, N, C, N, 0.0, C, N);				
	
	return C;
	
	printf("BLAS SOLVER\n");
	return NULL;
}
