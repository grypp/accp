#include "CUDAFunctions.hxx"

using namespace std;

namespace accp {

#if 0
template <typename T>
__device__ __inline__ void gr_copyin(T * dst, T * src, size_t num_element)
{
	for (size_t i = 0; i < num_element; i += gr_btnumf())
	{
		size_t pos = i + gr_btidf();
		if (pos < num_element)
		{
			dst[pos] = src[pos];
		}
	}
#endif
}
