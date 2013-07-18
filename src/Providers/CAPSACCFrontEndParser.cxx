/*
 * CAPSACCFrontEndParser.cxx
 *
 *  Created on: May 23, 2013
 *      Author: guray ozen
 */

#include "CAPSACCFrontEndParser.hxx"

namespace accp {
	namespace caps {

		/*
		 * signature acc call function
		 * void openacci_call(const char * file_name,int line_number,const char * function_name);
		 */
		string FrontEnd_Parser(fstream &fin, string *grouplet, string *ipcopyvalues) {
			string line, retFunction;
			retFunction.reserve(500);

			string function;
			do {
				function = getFunction(fin, accp::caps::caps_fe_pushdata.c_str(), accp::caps::caps_fe_call.c_str());
				if (function.find("155 /* ipcopy */", 0) != std::string::npos) {
					string tmp;
					vector<string> parameters = accp::parse_function(function, &tmp);
					*ipcopyvalues = parameters[2];
					replaceAll(*ipcopyvalues, "\"", "");
					trim(*ipcopyvalues);
				} else if (function.find(accp::caps::caps_fe_call.c_str(), 0) != std::string::npos) {

					break;
				}
			} while (!function.empty());

			if (fin.eof()) {
				cout << "-----------------" << function << endl;
				cout << "There is no function" << endl;
				exit(-1);
			}

			vector<string> parameters = accp::parse_function(function, grouplet);
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
