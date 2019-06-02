/*
 *  * Tema 2 ASC
 *   * 2019 Spring
 *    * Catalin Olaru / Vlad Spoiala
 *     */
#include "utils.h"
#include<stdio.h>

/*
 *  * Add your optimized implementation here
 *   */
double* my_solver(int N, double *A, double* B) {
	
	double* inm(double *A, double *B, int N)
	{	
	
		int i, j, k;
		double* C = (double*)malloc(N * N * sizeof(double));
	
		for(i = 0; i < N; i++)
		{	
			double *origin_pa= &A[i * N];
              	        for (j = 0; j < N; j++) 
               	        {       double *pa = origin_pa;
                       	        double *pb = &B[j];
                                register double sum = 0.0;
                       		for (k = 0; k < N; k++) 
				{
                                	 sum += *pa * *pb;
                               		 pa++;
                               		 pb += N;
                        	}
                       	        C[i * N + j] = sum;
                	}
		}
	return C;
	}
	
	double* AT = malloc(N * N * sizeof(double));
	double* BT = malloc(N * N * sizeof(double));
	double* C = malloc(N * N * sizeof(double));
	double* D = malloc(N * N * sizeof(double));
	int i, j;

	for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                        AT[i * N + j] = A[j * N + i];

	C = inm (AT, B, N);


	for(i = 0; i < N; i++)
                for(j = 0; j < N; j++)
                {        A[i * N + j] = AT[j * N + i];
			 BT[i * N + j] = B[j * N + i];
		}	

	D = inm (BT, A, N);

	for(i = 0; i < N; i++)
               for(j = 0; j < N; j++)
			C[i * N + j] += D[i * N + j];

	for(i = 1; i < N; i++)
                for(j = 0; j < i; j++)
                        C[i * N + j] = 0;
	
	C = inm (C, C, N);

	free(AT);
	free(BT);
	free(C);
	free(D);

//	printf("OPT SOLVER\n");
	return NULL;	
}
