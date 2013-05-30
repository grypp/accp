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

void kernels_reduction() {
	unsigned int n = (int) (ds / sizeof(int));
	int *a = NULL;
	int z = 0;
	unsigned int i = 0;

	a = (int *) malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		a[i] = (int) rand();

	#pragma acc data copyin(a[0:n])
	{
		#pragma acc kernels
		#pragma acc loop reduction(+:z)
		for (i = 0; i < n; i++)
			z += a[i];

		#pragma acc kernels
		#pragma acc loop
		for (i = 0; i < n; i++)
			z += a[i];
	}

	if (n == 0) {
		printf("Z=%d\n", z);
	}
	free(a);
}
