/*
 * OMPSSParser.hxx
 *
 *  Created on: May 24, 2013
 *      Author: grypp
 */

#ifndef OMPSSPARSER_HXX_
#define OMPSSPARSER_HXX_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "../ACCParserUtils.hxx"
#include "../Providers/CAPSACCFrontEndParser.hxx"
#include "../Providers/CAPSACCKernelParser.hxx"
#include "../Providers/CAPSACCGroupletParser.hxx"
using namespace std;
using namespace accparser::caps;

namespace accparser {
	namespace ompss {

		//todo add acc->ompss key,value table
		static std::map<string, string> ompssReplaceTable;

		int FrontEnd_Parser(const char* fnameIn, const char* fnameOut, const char* fnameFE);
		int FrontEnd_Parser_internal(const char* fnameIn, const char* fnameOut, const char* fnameFE);
		void OmpSs_Parser(const char* fnameIn, const char* fnameOut, const char* fnameEx, bool removeFile,string CPPFLAGS);
	}
}

#endif /* OMPSSPARSER_HXX_ */
