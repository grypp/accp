/*
 * CAPSACCFrontEndParser.hxx
 *
 *  Created on: May 23, 2013
 *      Author: grypp
 */

#ifndef CAPSACCFRONTENDPARSER_HXX_
#define CAPSACCFRONTENDPARSER_HXX_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "CAPSACCRuntimeConst.hxx"
#include "../ACCParserUtils.hxx"

using namespace std;

namespace accparser {
	namespace caps {
		string FrontEnd_Parser(fstream &fin, string *grouplet, string *ipcopyvalues);
	}
}

#endif /* CAPSACCFRONTENDPARSER_HXX_ */
