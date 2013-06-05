/*
 * OMPSSPlugin.cxx
 *
 *  Created on: Jun 3, 2013
 *      Author: guray ozen
 */

#include "OMPSSPlugin.hxx"

namespace accparser {
	namespace ompss {

		int xxx(const char* fnameIn, const char* fnameOut) {
			fstream fin(fnameIn);
			ofstream fout(fnameOut);
			string line;

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find("#pragma", 0) != std::string::npos) {
					if (line.find("target(acc/cuda)", 0) != std::string::npos) {

						accparser::replaceAll(line, "copy_inout(", "copy(");
						accparser::replaceAll(line, "copy_in(", "copyin(");
						accparser::replaceAll(line, "copy_in(", "create(");
						accparser::replaceAll(line, "copy_out(", "copyout(");

						//TODO only kernels!
						accparser::replaceAll(line, "omp target device(acc/cuda)", "#pragma acc kernels ");

						accparser::replaceAll(line, "kernels", "");
						accparser::replaceAll(line, "parallel", "");
						accparser::replaceAll(line, "loop", "");

						fout << line << endl;

					} else continue;
				} else fout << line << endl;
			}

			return 1;
		}
	}
}

