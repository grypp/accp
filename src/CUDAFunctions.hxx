/*
 * CUDAFunctions.hxx
 *
 *  Created on: May 18, 2013
 *      Author: guray ozen
 */

#ifndef CUDAFUNCTIONS_HXX_
#define CUDAFUNCTIONS_HXX_

#include <iostream>
#include <string>
#include <cstring>

namespace accp {
	class CUDAFunctions {
	public:
		static __inline__ const char* gr_atidf() {
			return "blockDim.x * blockDim.y * blockIdx.x + threadIdx.y * blockDim.x + threadIdx.x";
		}
		static inline const char* gr_atidx() {
			return "(blockDim.x * blockIdx.x + threadIdx.x)";
		}

		static inline const char* gr_atidy() {
			return "(blockDim.y * blockIdx.y + threadIdx.y)";
		}

		static inline const char* gr_btidf() {
			return "(threadIdx.y * blockDim.x + threadIdx.x)";
		}

		static inline const  char* gr_btidx() {
			return "threadIdx.x";
		}

		static inline const char* gr_btidy() {
			return "threadIdx.y";
		}

		static inline const char* gr_btnumf() {
			return "(blockDim.x * blockDim.y)";
		}

		static inline const char* gr_btnumx() {
			return "blockDim.x";
		}

		static inline const char* gr_btnumy() {
			return "blockDim.y";
		}

		static inline const char* gr_gbidf() {
			return "(gridDim.x * blockIdx.y + blockIdx.x)";
		}

		static inline const char* gr_gbidx() {
			return "blockIdx.x";
		}

		static inline const char* gr_gbidy() {
			return "blockIdx.y";
		}

		static inline const char* gr_gbnumf() {
			return "(gridDim.x * gridDim.y)";
		}

		static inline const char* gr_gbnumx() {
			return "gridDim.x";
		}

		static inline const char* gr_gbnumy() {
			return "gridDim.y";
		}

		static inline const char* gr_atidminf() {
			return "blockDim.x * blockDim.y * blockIdx.x";
		}

		static inline const char* gr_atidminx() {
			return "blockDim.x * blockIdx.x";
		}

		static inline const char* gr_atidminy() {
			return "blockDim.y * blockIdx.y";
		}

		static inline const char* gr_barrier() {
			return "__syncthreads()";
		}

	};
}

#endif /* CUDAFUNCTIONS_HXX_ */
