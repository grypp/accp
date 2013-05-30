/*
 * OMPSSParser.cxx
 *
 *  Created on: May 24, 2013
 *      Author: grypp
 */

#include "OMPSSParser.hxx"

namespace accparser {
	namespace ompss {

		//return last line
		string removeBracket(fstream &fin) {
			string line;
			std::getline(fin, line);
			if (line.find("{", 0) != std::string::npos) {
				int bracketCnt = 1;
				while (bracketCnt != 0) {
					std::getline(fin, line);
					if (line.find("{", 0) != std::string::npos) bracketCnt++;
					else if (line.find("}", 0) != std::string::npos) bracketCnt--;
				}
			}
			return line;
		}

		int FrontEnd_Parser(const char* fnameIn, const char* fnameOut, const char* fnameFE) {
			fstream fin(fnameIn), finFE(fnameFE);
			ofstream fout(fnameOut);
			stringstream ss, ss_sign;
			string line;
			vector<string> grouplets;

//preparing
			while (!finFE.eof()) {
				std::getline(finFE, line);
				if (line.find(accparser::func_main, 0) != std::string::npos) break;
			}

			if (!fin.good()) return 1;

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find(accparser::acc_pragma, 0) != std::string::npos) {
					accparser::replaceAll(line, "copy(", "copy_inout(");
					accparser::replaceAll(line, "copyin(", "copy_in(");
					accparser::replaceAll(line, "create(", "copy_in(");
					accparser::replaceAll(line, "copyout(", "copy_out(");

					accparser::replaceAll(line, "acc", "omp target device(cuda)");

					accparser::replaceAll(line, "kernels", "");
					accparser::replaceAll(line, "parallel", "");
					accparser::replaceAll(line, "loop", "");

					ss << line << endl;
					ss << "\t#pragma omp task " << endl;

					//that's function remover!!!
					line = removeBracket(fin);
					while (accparser::searchLineInArray(C_LeX, C_LeX_N, line))
						line = removeBracket(fin);

					//that's function adder!!!
					ss << accparser::caps::FrontEnd_Parser(finFE, &line) << endl;
					grouplets.push_back(line);

					ss << "\t#pragma omp taskwait " << endl;

				} else ss << line << endl;
			}
			stringstream signset;

			for (int i = 0; i < grouplets.size(); ++i) {
				finFE.seekg(0, std::ios::beg);
				string fe = getFunction(finFE, grouplets[i].c_str(), 1);
				replaceAll(fe, grouplets[i], grouplets[i] + "_internal_1");
				signset << fe << ';' << endl;
			}
			while (!ss.eof()) {
				std::getline(ss, line);
				if (line.find(accparser::func_main, 0) != std::string::npos) fout << signset.str() << line << endl;
				else {

					for (int i = 0; i < grouplets.size(); ++i) {
						if (line.find(grouplets[i], 0) != std::string::npos) {
							replaceAll(line, grouplets[i], grouplets[i] + "_internal_1");
							break;
						}
					}

					fout << line << endl;
				}
			}

			fin.close();
			fout.close();
			finFE.close();

			return 1;
		}
	}
}

