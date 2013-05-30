/*
 * CAPSACCFrontEndParser.cxx
 *
 *  Created on: May 23, 2013
 *      Author: guray ozen
 */

#include "CAPSACCFrontEndParser.hxx"

namespace accparser {
	namespace caps {

		/*
		 * signature acc call function
		 * void openacci_call(const char * file_name,int line_number,const char * function_name);
		 */
		string FrontEnd_Parser(fstream &fin, string *grouplet) {
			//fstream fin(fnameIn);
			string line, retFunction;
			retFunction.reserve(500);

			string function = getFunction(fin, accparser::caps::caps_fe_call.c_str());
			if (fin.eof()) throw "There is no function";

			vector<string> parameters = accparser::parse_function(function, grouplet);
			//todo function paramater getter/setter with param name. Like a binder with hastable
			trim(parameters.back());
			function = parameters.back().substr(1, parameters.back().size() - 2);

			*grouplet = function;
			function += +'(';
			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find(function, 0) != std::string::npos) {
					retFunction.append("\t");
					retFunction.append(line);
					retFunction.append("\n");
					break;
				}
			}

			return retFunction;
		}

	}
}
