/*
 * CommonKernelFunctions.hxx
 *
 *  Created on: May 18, 2013
 *      Author: guray ozen
 */

#ifndef COMMONKERNELFUNCTIONS_HXX_
#define COMMONKERNELFUNCTIONS_HXX_

namespace accp {
	class KernelFunctions {
	public:
#ifndef _WIN32
		static __inline__ const char* int08() {return "__int8_t";}
		static __inline__ const char* int16() {return "__int16_t";}
		static __inline__ const char* int32() {return "__int32_t";}
		static __inline__ const char* int64() {return "__int64_t";}
		static __inline__ const char* uint08() {return "__uint8_t";}
		static __inline__ const char* uint16() {return "__uint8_t";}
		static __inline__ const char* uint32() {return "__uint8_t";}
		static __inline__ const char* uint64() {return "__uint8_t";}
#else
		//not yet
#endif
	};
}

#endif /* COMMONKERNELFUNCTIONS_HXX_ */
