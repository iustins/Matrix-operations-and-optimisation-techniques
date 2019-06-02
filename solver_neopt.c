/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include<cblas.h>

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	
	int i, j, k;
	double* C = calloc(N * N, sizeof(double));
	double* D = calloc(N * N, sizeof(double));
	double* AT = calloc(N * N, sizeof(double));
	double* BT = calloc(N * N, sizeof(double));
	
	for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                        AT[i * N + j] = A[j * N + i];

        for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                {       C[i * N + j] = 0;
                        for(k = 0; k < N; k++)
                                C[i * N + j] += AT[i * N + k] * B[k * N + j];
		}

	for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                        BT[i * N + j] = B[j * N + i];

        for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                        A[i * N + j] = AT[j * N + i];

        for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                {       D[i * N + j] = 0;
                        for(k = 0; k < N; k++)
                                D[i * N + j] += BT[i * N + k] * A[k * N + j];
                }

	for(i = 0; i < N * N; i++)
                C[i] += D[i];

        for(i = 1; i < N; i++)
                for(j = 0; j < i; j++)
                                C[i * N + j] = 0;

        for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                {       D[i * N + j] = 0;
                        for(k = 0; k < N; k++)
                                D[i * N + j] += C[i * N + k] * C[k * N + j];
                }

        C = D;

	return C;
	
	printf("NEOPT SOLVER\n");
	return NULL;
}
