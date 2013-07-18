/*
 * OMPSSPlugin.cxx
 *
 *  Created on: Jun 3, 2013
 *      Author: guray ozen
 */

#include "OMPSSPlugin.hxx"

namespace accp {
	namespace ompss {

		int xxx(const char* fnameIn, const char* fnameOut) {
			fstream fin(fnameIn);
			ofstream fout(fnameOut);
			string line;

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find("#pragma", 0) != std::string::npos) {
					if (line.find("target(acc/cuda)", 0) != std::string::npos) {

						accp::replaceAll(line, "copy_inout(", "copy(");
						accp::replaceAll(line, "copy_in(", "copyin(");
						accp::replaceAll(line, "copy_in(", "create(");
						accp::replaceAll(line, "copy_out(", "copyout(");

						//TODO only kernels!
						accp::replaceAll(line, "omp target device(acc/cuda)", "#pragma acc kernels ");

						accp::replaceAll(line, "kernels", "");
						accp::replaceAll(line, "parallel", "");
						accp::replaceAll(line, "loop", "");

						fout << line << endl;

					} else continue;
				} else fout << line << endl;
			}

			return 1;
		}
	}
}

