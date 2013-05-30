/*
 * kernels_nested.c
 *
 *  Created on: May 30, 2013
 *      Author: grypp
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void kernels_nested(int *a, int *b, int n,int c[n][n]);

int main(){
	int i,j,n=10;

	int *a = (int *) malloc(n * sizeof(int));
	int *b = (int *) malloc(n * sizeof(int));
	int c2d[n][n];

	for(i=0; i<n; i++)for(j=0; j<n; j++)c2d[i][j]=0;

	kernels_nested(a,b,n,c2d);

    for(i=0; i<n; i++) fprintf(stdout,"%d\t",a[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",b[i]);printf("\n");

    for(i=0; i<n; i++)
    {
    	for(j=0; j<n; j++)
    		fprintf(stdout,"%d\t",c2d[i][j]);
    	printf("\n");
    }
}

void kernels_nested(int *a, int *b, int n,int c[n][n]) {
	unsigned int j,i = 0;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		a[i] = (int) rand() % 10;
		b[i] = (int) rand() % 10;
	}

	#pragma acc kernels loop copyin(a[0:n],b[0:n]) copyout(c[0:n])
	for (i = 0; i < n; i++)
		#pragma acc loop
		for (j = i; j < n; j++)
			c[i][j] = a[j] + b[j];

}
