
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
extern "C" CDLT_API  CDLT_API void __hmpp_acc_region__x2bhsmxg(hmpprt::s32 sz, hmpprt::s32* __hmpp_addr__i, hmpprt::s32* __hmpp_addr__j, hmpprt::s32* __hmpp_addr__k, hmpprt::s32 n, double fac, double* a0, double* a1)
;
#endif // __CUDACC__



# 5 "<preprocessor>"

#ifndef __CUDACC__
CDLT_API void __hmpp_acc_region__x2bhsmxg_internal_1(hmpprt::s32 sz, hmpprt::s32* __hmpp_addr__i, hmpprt::s32* __hmpp_addr__j, hmpprt::s32* __hmpp_addr__k, hmpprt::s32 n, double fac, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  a0, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  a1)
;
#endif // __CUDACC__




#ifndef __CUDACC__
static hmpprt::CUDAGrid * __hmpp_acc_region__x2bhsmxg_parallel_region_1 = 0;
#else

extern "C" __global__ void __hmpp_acc_region__x2bhsmxg_parallel_region_1(double* a0_1, double* a1_1, double fac_1, hmpprt::s32* i_2, hmpprt::s32* j_2, hmpprt::s32* k_2, hmpprt::s32 n_1, hmpprt::s32 sz_1)
{
 if (1 < n_1+1)
 {
  hmpprt::s32 nbiter_1;
  hmpprt::s32 firstiter_1;
  hmpprt::s32 lastiter_1;
  hmpprt::s32 tmp_6;
  nbiter_1 = 1+(n_1-1)/16;
  firstiter_1 = (hmpprt::gr_gbidx())*nbiter_1;
  lastiter_1 = ((firstiter_1+nbiter_1-1) < (n_1-1) ? (firstiter_1+nbiter_1-1) : (n_1-1));
  hmpprt::s32 i_1;
  # 135 "stencil.c"
  for (i_1 = firstiter_1+(hmpprt::gr_btidy()) ; i_1 <= lastiter_1 ; i_1 = i_1+(hmpprt::gr_btnumy()))
  {
   if (1 < n_1+1)
   {
    hmpprt::s32 tmp_4;
    hmpprt::s32 j_1;
    hmpprt::s32 end_2;
    # 137 "stencil.c"
    for (j_1 = (hmpprt::gr_btidx()), end_2 = n_1-1 ; j_1 <= end_2 ; j_1 = j_1+(hmpprt::gr_btnumx()))
    {
     if (1 < n_1+1)
     {
      hmpprt::s32 k_1;
      hmpprt::s32 end_3;
      # 139 "stencil.c"
      for (k_1 = 0, end_3 = n_1-1 ; k_1 <= end_3 ; k_1 = k_1+1)
      {
       # 143 "stencil.c"
       a1_1[(i_1+1)*sz_1*sz_1+(j_1+1)*sz_1+(k_1+1)] = (a0_1[(((hmpprt::s32 ) (i_1*1+1)))*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))-1)*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[(((hmpprt::s32 ) (i_1*1+1)))*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))+1)*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))-1)*sz_1*sz_1+(((hmpprt::s32 ) (j_1*1+1)))*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))+1)*sz_1*sz_1+(((hmpprt::s32 ) (j_1*1+1)))*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))-1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))-1)*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))-1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))+1)*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))+1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))-1)*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))+1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))+1)*sz_1+(((hmpprt::s32 ) (k_1*1+1)))]+a0_1[(((hmpprt::s32 ) (i_1*1+1)))*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))-1)*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[(((hmpprt::s32 ) (i_1*1+1)))*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))+1)*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))-1)*sz_1*sz_1+(((hmpprt::s32 ) (j_1*1+1)))*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))+1)*sz_1*sz_1+(((hmpprt::s32 ) (j_1*1+1)))*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))-1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))-1)*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))-1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))+1)*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))+1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))-1)*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[((((hmpprt::s32 ) (i_1*1+1)))+1)*sz_1*sz_1+((((hmpprt::s32 ) (j_1*1+1)))+1)*sz_1+((((hmpprt::s32 ) (k_1*1+1)))-1)]+a0_1[(i_1+1)*sz_1*sz_1+(j_1+(1-1))*sz_1+(k_1+2)]+a0_1[(i_1+1)*sz_1*sz_1+(j_1+2)*sz_1+(k_1+2)]+a0_1[i_1*sz_1*sz_1+(j_1+1)*sz_1+(k_1+2)]+a0_1[(i_1+2)*sz_1*sz_1+(j_1+1)*sz_1+(k_1+2)]+a0_1[i_1*sz_1*sz_1+j_1*sz_1+(k_1+2)]+a0_1[i_1*sz_1*sz_1+(j_1+2)*sz_1+(k_1+2)]+a0_1[(i_1+2)*sz_1*sz_1+j_1*sz_1+(k_1+2)]+a0_1[(i_1+2)*sz_1*sz_1+(j_1+2)*sz_1+(k_1+2)]+a0_1[(i_1+1)*sz_1*sz_1+(j_1+1)*sz_1+k_1]+a0_1[(i_1+1)*sz_1*sz_1+(j_1+1)*sz_1+(k_1+2)])*fac_1;
      }
      (*k_2) = n_1+1;
     }
     else
     {
      (*k_2) = 1;
     }
    }
    tmp_4 = n_1+1;
    if ((hmpprt::gr_btidx()) == 0)
    {
     (*j_2) = tmp_4;
    }
   }
   else
   {
    if ((hmpprt::gr_btidx()) == 0)
    {
     (*j_2) = 1;
    }
   }
  }
  (hmpprt::gr_barrier());
  tmp_6 = n_1+1;
  (hmpprt::gr_barrier());
  if ((hmpprt::gr_btidf()) == 0)
  {
   (*i_2) = tmp_6;
  }
 }
 else
 {
  (hmpprt::gr_barrier());
  (hmpprt::gr_barrier());
  if ((hmpprt::gr_btidf()) == 0)
  {
   (*i_2) = 1;
  }
 }
}
#endif // __CUDACC__



# 5 "<preprocessor>"

#ifndef __CUDACC__
CDLT_API void __hmpp_acc_region__x2bhsmxg_internal_1(hmpprt::s32 sz, hmpprt::s32* __hmpp_addr__i, hmpprt::s32* __hmpp_addr__j, hmpprt::s32* __hmpp_addr__k, hmpprt::s32 n, double fac, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  a0, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double>  a1)
{
 # 7 "<preprocessor>"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  k;
 hmpprt::Context::getInstance()->allocate((void **) (&k), hmpprt::MS_CUDA_GLOB, 4);
 # 7 "<preprocessor>"
 (*k) = __hmpp_addr__k[0];
 # 8 "<preprocessor>"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  j;
 hmpprt::Context::getInstance()->allocate((void **) (&j), hmpprt::MS_CUDA_GLOB, 4);
 # 8 "<preprocessor>"
 (*j) = __hmpp_addr__j[0];
 # 9 "<preprocessor>"
 hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,hmpprt::s32>  i;
 hmpprt::Context::getInstance()->allocate((void **) (&i), hmpprt::MS_CUDA_GLOB, 4);
 if (1)
 {
  hmpprt::CUDAGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(16);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8);
  __hmppcg_call.addLocalParameter(&a0, 8, "a0_1");
  __hmppcg_call.addLocalParameter(&a1, 8, "a1_1");
  __hmppcg_call.addLocalParameter(&fac, 8, "fac_1");
  __hmppcg_call.addLocalParameter(&i, 8, "i_2");
  __hmppcg_call.addLocalParameter(&j, 8, "j_2");
  __hmppcg_call.addLocalParameter(&k, 8, "k_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (n), "n_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (sz), "sz_1");
  __hmppcg_call.launch(__hmpp_acc_region__x2bhsmxg_parallel_region_1, hmpprt::Context::getInstance()->getCUDADevice());
 }
 ;
 # 33 "<preprocessor>"
 __hmpp_addr__i[0] = (*i);
 # 34 "<preprocessor>"
 __hmpp_addr__j[0] = (*j);
 # 35 "<preprocessor>"
 __hmpp_addr__k[0] = (*k);
 hmpprt::Context::getInstance()->free((void **) (&k));
 hmpprt::Context::getInstance()->free((void **) (&j));
 hmpprt::Context::getInstance()->free((void **) (&i));
}
#endif // __CUDACC__



# 5 "<preprocessor>"

#ifndef __CUDACC__
extern "C" CDLT_API  CDLT_API void __hmpp_acc_region__x2bhsmxg(hmpprt::s32 sz, hmpprt::s32* __hmpp_addr__i, hmpprt::s32* __hmpp_addr__j, hmpprt::s32* __hmpp_addr__k, hmpprt::s32 n, double fac, double* a0, double* a1)
{
 (__hmpp_acc_region__x2bhsmxg_internal_1(sz, __hmpp_addr__i, __hmpp_addr__j, __hmpp_addr__k, n, fac, hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (a0), hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB,double> (a1)));
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
    __hmpp_acc_region__x2bhsmxg_parallel_region_1 = new hmpprt::CUDAGrid(m, "__hmpp_acc_region__x2bhsmxg_parallel_region_1");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("__hmpp_acc_region__x2bhsmxg", "prototype __hmpp_acc_region__x2bhsmxg(sz: s32, __hmpp_addr__i: ^host s32, __hmpp_addr__j: ^host s32, __hmpp_addr__k: ^host s32, n: s32, fac: double, a0: ^cudaglob double, a1: ^cudaglob double)");

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
    m = __hmpp_acc_region__x2bhsmxg_parallel_region_1->getModule();
    delete __hmpp_acc_region__x2bhsmxg_parallel_region_1;

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
