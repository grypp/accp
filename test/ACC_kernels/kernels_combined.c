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

void kernels_combined() {

	unsigned int n = (int) (ds / sizeof(int));
	int *a = NULL;
	unsigned int i = 0;

	a = (int *) malloc(n * sizeof(int));

	#pragma acc kernels loop create(a[0:n])
	for (i = 0; i < n; i++)
		a[i] = i;

	#pragma acc kernels create(a[0:n])
	#pragma acc loop
	for (i = 0; i < n; i++)
		a[i] = i;

	free(a);
}
