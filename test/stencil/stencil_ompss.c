#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <omp.h>

#define ITERATIONS 10
#define FAC (1./26)
#define TOLERANCE 1.0e-15

/* Forward Declarations of utility functions*/
double max_diff(double *, double *, int);
double stencil();

void __hmpp_acc_region__x2bhsmxg_internal_1(int sz, int __hmpp_addr__i[1], int __hmpp_addr__j[1], int __hmpp_addr__k[1], int n, double fac, double *a0, double *a1);
void __hmpp_acc_region__wmf7vvd0_internal_1(int sz, int __hmpp_addr__i[1], int __hmpp_addr__j[1], int __hmpp_addr__k[1], int n, double *a0, double *a1);
int main(int argc, char **argv) {
	int i = 0, reps = 10;
	double tmp = 0;
	char* name = "stencil";
	double times[10];

	printf("%d \n", reps);
	for (i = 0; i < reps; i++) {
		tmp = stencil();
		if (tmp == -10000) {
			printf("Memory allocation failure in %s\n", name);
			times[i] = 0;
		} else if (tmp == -11000) {
			printf("CPU/GPU mismatch in %s\n", name);
			times[i] = 0;
		} else {
			times[i] = tmp;
		}
	}
}

double stencil() {
	unsigned int datasize=1048576;
	int sz = cbrt((datasize / sizeof(double)) / 2);
	int i, j, k, iter;
	int n = sz - 2;
	double fac = FAC;
	double t1, t2;
	double md;

	double *a0 = (double*) malloc(sizeof(double) * sz * sz * sz);
	double *device_result = (double*) malloc(sizeof(double) * sz * sz * sz);
	double *a1 = (double*) malloc(sizeof(double) * sz * sz * sz);
	double *host_result = (double*) malloc(sizeof(double) * sz * sz * sz);
	double *a0_init = (double*) malloc(sizeof(double) * sz * sz * sz);

	if (a0 == NULL || device_result == NULL || a1 == NULL || host_result == NULL || a0_init == NULL) {
		return (-10000);
	}

	/* zero all of array (including halos) */
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz; j++) {
			for (k = 0; k < sz; k++) {
				a0[i * sz * sz + j * sz + k] = 0.0;
			}
		}
	}

	/* use random numbers to fill interior */
	for (i = 1; i < n + 1; i++) {
		for (j = 1; j < n + 1; j++) {
			for (k = 1; k < n + 1; k++) {
				a0[i * sz * sz + j * sz + k] = (double) rand() / (double) (1.0 + RAND_MAX);
			}
		}
	}

	/* save initial input array for later GPU run */
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz; j++) {
			for (k = 0; k < sz; k++) {
				a0_init[i * sz * sz + j * sz + k] = a0[i * sz * sz + j * sz + k];
			}
		}
	}

void __hmpp_acc_region__x2bhsmxg_internal_1(int sz, int __hmpp_addr__i[1], int __hmpp_addr__j[1], int __hmpp_addr__k[1], int n, double fac, double *a0, double *a1);
void __hmpp_acc_region__wmf7vvd0_internal_1(int sz, int __hmpp_addr__i[1], int __hmpp_addr__j[1], int __hmpp_addr__k[1], int n, double *a0, double *a1);
	/* run main computation on host */

	for (iter = 0; iter < ITERATIONS; iter++) {

		for (i = 1; i < n + 1; i++) {
			for (j = 1; j < n + 1; j++) {
				for (k = 1; k < n + 1; k++) {
					a1[i * sz * sz + j * sz + k] = (a0[i * sz * sz + (j - 1) * sz + k] + a0[i * sz * sz + (j + 1) * sz + k] + a0[(i - 1) * sz * sz + j * sz + k] + a0[(i + 1) * sz * sz + j * sz + k] + a0[(i - 1) * sz * sz + (j - 1) * sz + k] + a0[(i - 1) * sz * sz + (j + 1) * sz + k] + a0[(i + 1) * sz * sz + (j - 1) * sz + k] + a0[(i + 1) * sz * sz + (j + 1) * sz + k]
							+ a0[i * sz * sz + (j - 1) * sz + (k - 1)] + a0[i * sz * sz + (j + 1) * sz + (k - 1)] + a0[(i - 1) * sz * sz + j * sz + (k - 1)] + a0[(i + 1) * sz * sz + j * sz + (k - 1)] + a0[(i - 1) * sz * sz + (j - 1) * sz + (k - 1)] + a0[(i - 1) * sz * sz + (j + 1) * sz + (k - 1)] + a0[(i + 1) * sz * sz + (j - 1) * sz + (k - 1)] + a0[(i + 1) * sz * sz + (j + 1) * sz + (k - 1)]
							+ a0[i * sz * sz + (j - 1) * sz + (k + 1)] + a0[i * sz * sz + (j + 1) * sz + (k + 1)] + a0[(i - 1) * sz * sz + j * sz + (k + 1)] + a0[(i + 1) * sz * sz + j * sz + (k + 1)] + a0[(i - 1) * sz * sz + (j - 1) * sz + (k + 1)] + a0[(i - 1) * sz * sz + (j + 1) * sz + (k + 1)] + a0[(i + 1) * sz * sz + (j - 1) * sz + (k + 1)] + a0[(i + 1) * sz * sz + (j + 1) * sz + (k + 1)]
							+ a0[i * sz * sz + j * sz + (k - 1)] + a0[i * sz * sz + j * sz + (k + 1)]) * fac;
				}
			}
		}

		for (i = 1; i < n + 1; i++) {
			for (j = 1; j < n + 1; j++) {
				for (k = 1; k < n + 1; k++) {
					a0[i * sz * sz + j * sz + k] = a1[i * sz * sz + j * sz + k];
				}
			}
		}

	} /* end iteration loop */

	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz; j++) {
			for (k = 0; k < sz; k++) {
				host_result[i * sz * sz + j * sz + k] = a0[i * sz * sz + j * sz + k];
			}
		}
	}

	/* copy initial array back to a0 */
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz; j++) {
			for (k = 0; k < sz; k++) {
				a0[i * sz * sz + j * sz + k] = a0_init[i * sz * sz + j * sz + k];
			}
		}
	}

	t1 = omp_get_wtime();
#pragma omp target device(cuda) data copy_inout(a0[0:sz*sz*sz]), create(a1[0:sz*sz*sz], i,j,k,iter), copy_in(sz,fac,n)
	#pragma omp task 
	        __hmpp_acc_region__x2bhsmxg_internal_1(sz, &i, &j, &k, n, fac, a0, a1);

	#pragma omp taskwait 
#pragma omp target device(cuda) wait
	#pragma omp task 
	        __hmpp_acc_region__wmf7vvd0_internal_1(sz, &i, &j, &k, n, a0, a1);

	#pragma omp taskwait 

	memcpy(&device_result[0], &a0[0], sizeof(double) * sz * sz * sz);
	md = max_diff(&host_result[0], &device_result[0], sz);

	/* Free malloc'd memory to prevent leaks */
	free(a0);
	free(a0_init);
	free(a1);
	free(host_result);
	free(device_result);

	if (md < TOLERANCE) {
		/* printf ("GPU matches host to within tolerance of %1.1e\n\n", TOLERANCE); */
		return (t2 - t1);
	} else {
		/* printf ("WARNING: GPU does not match to within tolerance of %1.1e\nIt is %lf\n", TOLERANCE, md); */
		return (-11000);
	}

}

/* Utility Functions */

double max_diff(double *array1, double *array2, int sz) {
	double tmpdiff, diff;
	int i, j, k;
	int n = sz - 2;
	diff = 0.0;

	for (i = 1; i < n + 1; i++) {
		for (j = 1; j < n + 1; j++) {
			for (k = 1; k < n + 1; k++) {
				tmpdiff = fabs(array1[i * sz * sz + j * sz + k] - array2[i * sz * sz + j * sz + k]);
				if (tmpdiff > diff) diff = tmpdiff;

			}
		}
	}
	return diff;
}



