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

void main() {

	int i,j,n=10;
	int *a ,*b= NULL;

	a = (int *) malloc(n * sizeof(int));
	b = (int *) malloc(n * sizeof(int));

	for (i = 0; i < n; i++){
		a[i] = i;
		b[i] = i+1;
	}
	for(i=0; i<n; i++) fprintf(stdout,"%d\t",a[i]);printf("\n");
	for(i=0; i<n; i++) fprintf(stdout,"%d\t",b[i]);printf("\n");
	printf("\n");
	#pragma acc data copy(a[0:n],b[0:n])
	{
		#pragma acc kernels
		for (i = 0; i < n; i++)
			a[i] = i+10;

		for (i = 0; i < n; i++)
			a[i] = i+20;

		#pragma acc kernels
		for (i = 0; i < n; i++)
			b[i] = a[i]+i;
	}

	for(i=0; i<n; i++) fprintf(stdout,"%d\t",a[i]);printf("\n");
	for(i=0; i<n; i++) fprintf(stdout,"%d\t",b[i]);printf("\n");
	printf("\n");
	#pragma acc data copy(a[0:n],b[0:n])
	{
		#pragma acc kernels
		for (i = 0; i < n; i++)
			a[i] = i+10;

		for (i = 0; i < n; i++)
			a[i] = i+20;

		#pragma acc update device(a[0:n])

		#pragma acc kernels
		for (i = 0; i < n; i++)
			b[i] = a[i]+i;
	}

	for(i=0; i<n; i++) fprintf(stdout,"%d\t",a[i]);printf("\n");
	for(i=0; i<n; i++) fprintf(stdout,"%d\t",b[i]);printf("\n");

	free(a);
	free(b);
}
