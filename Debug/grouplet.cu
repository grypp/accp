#include <stdio.h>
#include <cuda.h>
extern "C" __global__ void __hmpp_acc_region__x2fftoqf_loop1D_1(__int32_t n, __int32_t* a, __int32_t* b, __int32_t* c);

void __hmpp_acc_region__x2fftoqf_internal_1(__int32_t n,__int32_t*  a,__int32_t*  b,__int32_t*  c, __int32_t* __hmpp_addr__i)
{
	dim3 threadsPerBlock((n-1)/128+1,1);
	dim3 numBlocks(32,4);
	__hmpp_acc_region__x2fftoqf_loop1D_1<<<numBlocks,threadsPerBlock>>>((n),a,b,c);
}
