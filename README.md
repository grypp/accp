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

    #pragma omp target device(acc/cuda) copy_in(a[0:n],b[0:n]) copy_out(c[0:n])
    #pragma omp task
    for(i=0; i<n; i++) {
        c[i] = a[i] + b[i];
    }
    #pragma omp taskwait

TODO
Currently it support only CAPS openACC. 
