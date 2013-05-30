/*
 * dataregion.c
 *
 *  Created on: May 30, 2013
 *      Author: grypp
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <stdint.h>

double contig_htod() {

	extern unsigned int datasize;
	unsigned int i = 0;
	double t1_start = 0;
	double t1_end = 0;
	unsigned int n = (unsigned int) (datasize / sizeof(int));
	int *a = (int *) malloc(n * sizeof(int));

	if (a == NULL) {
		/* Something went wrong in the memory allocation here, fail gracefully */
		return (-10000);
	}

	for (i = 0; i < n; i++) {
		a[i] = (int) rand();
	}

	t1_start = omp_get_wtime();
#pragma acc data copyin(a[0:n])
	{
		if (n == 0) {
			a[0] = (int) 1;
		}
	}
	t1_end = omp_get_wtime();

	free(a);
	return (t1_end - t1_start);
}

double contig_dtoh() {

	extern unsigned int datasize;
	unsigned int i = 0;
	double t1_start = 0;
	double t1_end = 0;
	unsigned int n = (int) (datasize / sizeof(int));
	int *a = (int *) malloc(n * sizeof(int));

	if (a == NULL) {
		/* Something went wrong in the memory allocation here, fail gracefully */
		return (-10000);
	}

	for (i = 0; i < n; i++) {
		a[i] = (int) rand();
	}

	t1_start = omp_get_wtime();
#pragma acc data copyout(a[0:n])
	{
		if (n == 0) {
			a[0] = (int) 1;
		}
	}
	t1_end = omp_get_wtime();

	free(a);
	return (t1_end - t1_start);
}

double sliced_dtoh() {

	extern unsigned int datasize;
	double t1_start = 0;
	double t1_end = 0;
	int i = 0;
	int sqrtn = 0;
	int **a = NULL;
	int *aptr = NULL;
	unsigned int n = (unsigned int) (datasize / sizeof(int));
	sqrtn = sqrt((int) n); /* sqrtn is the number of rows (or cols) you have in the array */
	a = (int**) malloc(sqrtn * sizeof(int*));

	if (a == NULL) {
		/* Something went wrong in the memory allocation here, fail gracefully */
		return (-10000);
	}

	for (i = 0; i < sqrtn; i++) {
		a[i] = (int*) malloc(sqrtn * sizeof(int));
		if (a[i] == NULL) {
			/* Something went wrong in the memory allocation here, fail gracefully */
			return (-10000);
		}
	}

	aptr = a[1];

	t1_start = omp_get_wtime();
#pragma acc data copyout(aptr[0:sqrtn])
	{
		if (n == 0) {
			a[0]++;
		}
	}
	t1_end = omp_get_wtime();

	for (i = 0; i < sqrtn; i++) {
		free(a[i]);
	}

	free(a);
	return (t1_end - t1_start);
}

double sliced_htod() {

	extern unsigned int datasize;
	unsigned int n = (int) (datasize / sizeof(int));
	int **a = NULL;
	int i = 0;
	int j = 0;
	double t1_start = 0;
	double t1_end = 0;
	int sqrtn = sqrt(n);
	int *aptr = NULL;
	a = (int**) malloc(sqrtn * sizeof(int*));
	if (a == NULL) {
		/* Something went wrong in the memory allocation here, fail gracefully */
		return (-10000);
	}
	for (i = 0; i < sqrtn; i++) {
		a[i] = (int*) malloc(sqrtn * sizeof(int));
		if (a[i] == NULL) {
			/* Something went wrong in the memory allocation here, fail gracefully */
			return (-10000);
		}
	}
	aptr = a[1];

	for (j = 0; j < sqrtn; j++) {
		for (i = 0; i < sqrtn; i++) {
			a[j][i] = (int) rand();
		}
	}

	t1_start = omp_get_wtime();

#pragma acc data copyin(aptr[0:sqrtn])
	{
		if (n == 0) {
			a[0]++;
		}
	}

	t1_end = omp_get_wtime();

	for (i = 0; i < sqrtn; i++) {
		free(a[i]);
	}

	free(a);

	return (t1_end - t1_start);
}




