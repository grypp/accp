/*

 * CAPSACCKernelParser.hxx
 *
 *  Created on: May 21, 2013
 *      Author: guray ozen
 */

#ifndef CAPSACCKERNELPARSER_HXX_
#define CAPSACCKERNELPARSER_HXX_


#include "../CUDAFunctions.hxx"
#include "../KernelFunctions.hxx"
#include "../ACCParserUtils.hxx"
#include "CAPSACCRuntimeConst.hxx"

using namespace std;

namespace accp {
	namespace caps {

		void parse_variable(string* line);
		int BackEnd_Parser_Kernel(const char* fnameIn, const char* fnameOut);

	}
}

#endif  CAPSACCKERNELPARSER_HXX_

