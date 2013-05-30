
#include <stdio.h>

#ifndef __CUDACC__
#include <stdlib.h>
#include <math.h>

#include <hmpprt/Grouplet.h>
#include <hmpprt/HostTypes.h>
#include <hmpprt/Context.h>
#include <hmpprt/CUDAGrid.h>
#include <hmpprt/CUDAModule.h>
#include <hmpprt/DeviceManager.h>
#include <hmpperr/hmpperr.h>

#ifdef _WIN32
#  define CDLT_API __declspec(dllexport)
#else /* ! _WIN32 */
#  define CDLT_API
#endif /* _WIN32 */

#else // ! __CUDACC__

#include <hmpprt/HostTypes.h>
#include <hmpprt/CUDAIntrinsics.h>

extern __shared__ int64_t hmpp_sharedmem[];
#endif // __CUDACC__

#define HMPPCG_WARP_SIZE 1  // Usually it should be 32, but we issued a bug on 2.1 capabilities devices



#ifndef __CUDACC__

#else


#endif

# 5 "<preprocessor>"

#ifndef __CUDACC__
extern "C" CDLT_API  CDLT_API void __hmpp_acc_region__x2fftoqf(hmpprt::s32 n, hmpprt::s32* a, hmpprt::s32* b, hmpprt::s32* c, hmpprt::s32* __hmpp_addr__i)
;
#endif // __CUDACC__



# 5 "<preprocessor>"

#ifndef __CUDACC__
CDLT_API void __hmpp_acc_region__x2fftoqf_internal_1(hmpprt::s32 n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  a, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  b, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  c, hmpprt::s32* __hmpp_addr__i)
;
#endif // __CUDACC__




#ifndef __CUDACC__
static hmpprt::CUDAGrid * __hmpp_acc_region__x2fftoqf_loop1D_1 = 0;
#else

extern "C" __global__ void __hmpp_acc_region__x2fftoqf_loop1D_1(hmpprt::s32 n, hmpprt::s32* a, hmpprt::s32* b, hmpprt::s32* c)
{
 # 7 "<preprocessor>"
 hmpprt::s32 i_1;
 i_1 = (hmpprt::gr_atidf());
 if (i_1 > n-1)
 {
  goto __hmppcg_label_1;
 }
 # 36 "vecadd.c"
 c[i_1] = a[i_1]+b[i_1];
 __hmppcg_label_1:;
}
#endif // __CUDACC__



# 5 "<preprocessor>"

#ifndef __CUDACC__
CDLT_API void __hmpp_acc_region__x2fftoqf_internal_1(hmpprt::s32 n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  a, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  b, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  c, hmpprt::s32* __hmpp_addr__i)
{
 # 7 "<preprocessor>"
 hmpprt::s32 i;
 if (0 < n)
 {
  if (n-1 >= 0)
  {
   hmpprt::CUDAGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((n-1)/128+1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (n), "n");
   __hmppcg_call.addLocalParameter(&a, 8, "a");
   __hmppcg_call.addLocalParameter(&b, 8, "b");
   __hmppcg_call.addLocalParameter(&c, 8, "c");
   __hmppcg_call.launch(__hmpp_acc_region__x2fftoqf_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
  }
  ;
  i = n;
 }
 else
 {
  i = 0;
 }
 # 16 "<preprocessor>"
 __hmpp_addr__i[0] = i;
}
#endif // __CUDACC__



# 5 "<preprocessor>"

#ifndef __CUDACC__
extern "C" CDLT_API  CDLT_API void __hmpp_acc_region__x2fftoqf(hmpprt::s32 n, hmpprt::s32* a, hmpprt::s32* b, hmpprt::s32* c, hmpprt::s32* __hmpp_addr__i)
{
 (__hmpp_acc_region__x2fftoqf_internal_1(n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (a), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (b), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32> (c), __hmpp_addr__i));
}
#endif // __CUDACC__




#ifndef __CUDACC__
extern "C" const char * hmpprt_cuda_get_gpu_code();

extern "C" CDLT_API void * hmpprt_init()
{
  try
  {
    hmpprt::CUDAModule * m = new hmpprt::CUDAModule(hmpprt_cuda_get_gpu_code());
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    __hmpp_acc_region__x2fftoqf_loop1D_1 = new hmpprt::CUDAGrid(m, "__hmpp_acc_region__x2fftoqf_loop1D_1");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("__hmpp_acc_region__x2fftoqf", "prototype __hmpp_acc_region__x2fftoqf(n: s32, a: ^cudaglob s32, b: ^cudaglob s32, c: ^cudaglob s32, __hmpp_addr__i: ^host s32)");

  }
  catch (hmpperr::Error & e)
  {
    return e.clone();
  }
  catch(...)
  {
    fprintf(stderr,"Unexpected error in hmpprt_init()\n");
    abort();
  }
  return 0;
}
#endif // __CUDACC__

#ifndef __CUDACC__
extern "C" CDLT_API void * hmpprt_fini()
{
  try
  {
    hmpprt::CUDAModule * m = 0;
    m = __hmpp_acc_region__x2fftoqf_loop1D_1->getModule();
    delete __hmpp_acc_region__x2fftoqf_loop1D_1;

    if(m)
      delete m;
  }
  catch (hmpperr::Error & e)
  {
    return e.clone();
  }
  catch(...)
  {
    fprintf(stderr,"Unexpected error in hmpprt_fini()\n");
    abort();
  }
  return 0;
}
#endif // __CUDACC__

// footer
