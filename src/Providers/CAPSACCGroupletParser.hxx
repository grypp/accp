/*
 * CAPSACCGroupletParser.hxx
 *
 *  Created on: May 21, 2013
 *      Author: grypp
 */

#ifndef CAPSACCGROUPLETPARSER_HXX_
#define CAPSACCGROUPLETPARSER_HXX_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "CAPSACCRuntimeConst.hxx"
#include "CAPSACCKernelParser.hxx"
#include "../ACCParserUtils.hxx"

using namespace std;

namespace accparser {
	namespace caps {

		typedef std::vector<string> SVector;
		typedef std::map<string, SVector> ParameterTable;

		typedef struct {
			string sizeX;
			string sizeY;
			string blockX;
			string dynamicMemSize;
			string blockY;
		} CUDAKernel;

		int BackEnd_Parser_Grouplet(const char* fnameIn, const char* fnameOut);
	}
}
#endif /* CAPSACCGROUPLETPARSER_HXX_ */
