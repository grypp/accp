//============================================================================
// Name        : portacc.cpp
// Author      : gurayozen
// Version     :
// Copyright   : openacc integration
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char* argv[] )
{

    // Size of vectors
    int n = 10;


    // Input vectors
    int * a;
    int * b;
    // Output vector
    int * c;

    // Size, in bytes, of each vector
    size_t bytes = n*sizeof(int);

    // Allocate memory for each vector
    a = (int*)malloc(bytes);
    b = (int*)malloc(bytes);
    c = (int*)malloc(bytes);

    // Initialize content of input vectors, vector a[i] = sin(i)^2 vector b[i] = cos(i)^2
    int i;
    for(i=0; i<n; i++) {
        a[i] = i;
        b[i] = (i+1);
    }

    // sum component wise and save result into vector c
    #pragma acc kernels copyin(a[0:n],b[0:n]), copyout(c[0:n])
    for(i=0; i<n; i++){
    	for(int j=i; j<n; j++)
    		c[j] += a[i] + b[i];
        c[j]=c[j]/n;
    }

    for(i=0; i<n; i++) fprintf(stdout,"%d\t",a[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",b[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",c[i]);printf("\n");

    // Sum up vector c and print result divided by n, this should equal 1 within error
    int sum = 0;
    for(i=0; i<n; i++) {

        sum += c[i];
    }

    printf("final result: %d\n", sum);

    // Release memory
    free(a);
    free(b);
    free(c);

    return 0;
}
