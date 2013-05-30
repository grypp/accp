#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void __hmpp_acc_region__2r7luxyf_internal_1(int n, int *a, int *b, int *c, int __hmpp_addr__i[1], int __hmpp_addr__j[1]);
void __hmpp_acc_region__up2b9qbv_internal_1(int n, int *a, int *c, int __hmpp_addr__i[1], int __hmpp_addr__j[1]);
void __hmpp_acc_region__mzp4y33h_internal_1(int n, int *b, int __hmpp_addr__i[1], int __hmpp_addr__j[1]);
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
	c[i] = 0;
    }
int asdasd=123;
#if 1
 int j=1;

    #pragma omp target device(cuda)  copy_in(a[0:n],b[0:n]), copy_inout(c[0:n])
	#pragma omp task 
	  __hmpp_acc_region__2r7luxyf_internal_1(n, a, b, c, &i, &j);

	#pragma omp taskwait 

    #pragma omp target device(cuda)  copy_in(a[0:n]), copy_inout(c[0:n])
	#pragma omp task 
	  __hmpp_acc_region__up2b9qbv_internal_1(n, a, c, &i, &j);

	#pragma omp taskwait 

    #pragma omp target device(cuda)  copy_inout(b[0:n])
	#pragma omp task 
	  __hmpp_acc_region__mzp4y33h_internal_1(n, b, &i, &j);

	#pragma omp taskwait 
#endif
#if 0
    #pragma omp target device(cuda)  copy_deps
    #pragma omp task in(a[0:n],b[0:n]) out(c[0:n])
        __hmpp_acc_region__yxqz3bjj_internal_1(n,a,b,c,&i);


    #pragma omp target device(cuda) copy_deps
    #pragma omp task in(a[0:n]) inout(c[0:n])
	__hmpp_acc_region__oyl4mtyv_internal_1(n,a,c,&i);
    #pragma omp taskwait

#endif
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",a[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",b[i]);printf("\n");
    for(i=0; i<n; i++) fprintf(stdout,"%d\t",c[i]);printf("\n");

    // Sum up vector c and print result divided by n, this should equal 1 within error
    int sum = 0;
    for(i=0; i<n; i++) {

        sum += c[i];
    }
    sum = sum;
    printf("final result: %d\n", sum);

    // Release memory
    free(a);
    free(b);
    free(c);

    return 0;
}


