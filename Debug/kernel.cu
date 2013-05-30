extern __shared__ int64_t hmpp_sharedmem[];
extern "C" __global__ void __hmpp_acc_region__x2fftoqf_loop1D_1(__int32_t n, __int32_t* a, __int32_t* b, __int32_t* c)
{
 __int32_t i_1;
 i_1 = (blockDim.x * blockDim.y * blockIdx.x + threadIdx.y * blockDim.x + threadIdx.x);
 if (i_1 > n-1)
 {
  goto __hmppcg_label_1;
 }
 c[i_1] = a[i_1]+b[i_1];
 __hmppcg_label_1:;
}

