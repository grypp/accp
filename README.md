accp
====

OpenACC parser and code generator for OmpSs(http://pm.bsc.es/ompss).

What is ACCP?
ACCP is source2source compiler. It uses OmpSs, OpenACC, General C compiler at background.
OpenACC code can be write with OmpSs style.
ACCP can compile OmpSs codes like OpenACC. 
ACCP can convert from OpenACC codes to OmpSs code and vice-versa.

Why?
In our opinion standart-openACC and OmpSs approaches are very similar each other. Our aim in this project, to prove it.
 

Very Simple Example: Vector Addition

	Your OmpSs codes can be like that anymore: 

    int main(void) {
 		double pi = 0.0f; long i;
  		#pragma omp target device(acc/cuda)
  		#pragma omp task
  		#pragma omp for  reduction(+:pi)
  		for (i=0; i<N; i++) {
     		double t= (double)((i+0.5)/N);
     		pi +=4.0/(1.0+t*t);
  		}
 		printf("pi=%16.15f\n",pi/N);
 	return 0;
	}

TODO
Currently it support only CAPS openACC. 
