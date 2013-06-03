/*
 * kernels_basic.c
 *
 *  Created on: May 30, 2013
 *      Author: grypp
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void kernels_basic(int *a,int *b,int *c,int *c2,int n);

int main(){
	int i,j,n=10;

	int *a = (int *) malloc(n * sizeof(int));
	int *b = (int *) malloc(n * sizeof(int));
	int *c = (int *) malloc(n * sizeof(int));
	int *c2 = (int *) malloc(n * sizeof(int));

	kernels_basic(a,b,c,c2,n);

    for(i=0; i<n; i++) fprintf(stdout,"%d\t",a[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",b[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",c[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",c2[i]);printf("\n");
}


void kernels_basic(int *a,int *b,int *c,int *c2,int n) {
	unsigned int i = 0;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		a[i] = (int) rand()%49;
		b[i] = (int) rand()%49;
	}

	#pragma acc kernels copyin(a[0:n],b[0:n]) copyout(c[0:n])
	for (i = 0; i < n; i++)
		c[i] = a[i]+b[i];

	#pragma acc kernels copyin(a[0:n],b[0:n]) copyout(c2[0:n])
	for (i = 0; i < n; i++)
		c2[i] = a[i]+b[i];

}
