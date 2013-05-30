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

# 18 "vaddported_ported.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  CDLT_API void add_vector(hmpprt::s32 n, float* y, float* a, float* b)
;
#endif // __CUDACC__



# 18 "vaddported_ported.cpp"

#ifndef __CUDACC__
CDLT_API void add_vector_internal_1(hmpprt::s32 n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  y, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  a, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  b)
;
#endif // __CUDACC__




#ifndef __CUDACC__
static hmpprt::CUDAGrid * add_vector_loop1D_1 = 0;
#else

extern "C" __global__ void add_vector_loop1D_1(hmpprt::s32 n, float* y, float* a, float* b)
{
 # 20 "vaddported_ported.cpp"
 hmpprt::s32 i_1;
 i_1 = (hmpprt::gr_atidf());
 if (i_1 > n-1)
 {
  goto __hmppcg_label_1;
 }
 # 21 "vaddported_ported.cpp"
 y[i_1] = a[i_1]+b[i_1];
 __hmppcg_label_1:;
}
#endif // __CUDACC__



# 18 "vaddported_ported.cpp"

#ifndef __CUDACC__
CDLT_API void add_vector_internal_1(hmpprt::s32 n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  y, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  a, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float>  b)
{
#if 1
 if (n-1 >= 0)
 {
  fprintf(stdout,"entered gry\n");
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX((n-1)/128+1);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(4);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (n), "n");
  __hmppcg_call.addLocalParameter(&y, 8, "y");
  __hmppcg_call.addLocalParameter(&a, 8, "a");
  __hmppcg_call.addLocalParameter(&b, 8, "b");
  __hmppcg_call.launch(add_vector_loop1D_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
#endif
}
#endif // __CUDACC__



# 18 "vaddported_ported.cpp"

#ifndef __CUDACC__
extern "C" CDLT_API  CDLT_API void add_vector(hmpprt::s32 n, float* y, float* a, float* b)
{
 (add_vector_internal_1(n, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float> (y), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float> (a), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,float> (b)));
}
#endif // __CUDACC__




#ifndef __CUDACC__
extern "C" const char * hmpprt_cuda_get_gpu_code();
extern "C" CDLT_API void * hmpprt_init()
{
 try
  {
    fprintf(stdout,"entered\n");
    hmpprt::CUDAModule * m = new hmpprt::CUDAModule(hmpprt_cuda_get_gpu_code());
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::CUDA);
    add_vector_loop1D_1 = new hmpprt::CUDAGrid(m, "add_vector_loop1D_1");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("add_vector", "prototype add_vector(n: s32, y: ^cudaglob float, a: ^cudaglob float, b: ^cudaglob float)");

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
fprintf(stdout,"exited\n");
  try
  {
    hmpprt::CUDAModule * m = 0;
    m = add_vector_loop1D_1->getModule();
    delete add_vector_loop1D_1;

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
