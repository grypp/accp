/*
 * level0_kernels.c
 *
 *  Created on: May 30, 2013
 *      Author: guray ozen
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

double ds = 1000000;

/* Kernels Invocation */
void kernels_invoc() {

	unsigned int i=0,n = (int) (ds / sizeof(int));
	int *a = NULL;

	a = (int *) malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		a[i] = (int) rand();

	#pragma acc data copyin(a[0:n],i,n)
	{
		#pragma acc kernels loop
		for (i = 0; i < n; i++)
			a[i] = 10 * i;

		#pragma acc kernels loop
		for (i = 0; i < n; i++)
			a[i] = 10 * a[i];

		#pragma acc kernels loop
		for (i = 0; i < n; i++) {
			a[i] = 10 * a[i];
			a[i] = 10 * a[i];
		}

	}

	free(a);
}
