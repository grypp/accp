//============================================================================
// Name        : ACCParser.cpp
// Author      : guray ozen
// Version     : 0.1
// Copyright   : openacc integration
// Description : Main in C++, Ansi-style
//============================================================================

#include "CAPSACCKernelParser.hxx"

using namespace std;

namespace accparser {
	namespace caps {

		void parse_variable(string* line) {
			KernelFunctions com_func;
			accparser::replaceAll(*line, caps::CAPS_Variables_List[0], com_func.int08());
			accparser::replaceAll(*line, caps::CAPS_Variables_List[1], com_func.int16());
			accparser::replaceAll(*line, caps::CAPS_Variables_List[2], com_func.int32());
			accparser::replaceAll(*line, caps::CAPS_Variables_List[3], com_func.int64());
			accparser::replaceAll(*line, caps::CAPS_Variables_List[4], com_func.uint08());
			accparser::replaceAll(*line, caps::CAPS_Variables_List[5], com_func.uint16());
			accparser::replaceAll(*line, caps::CAPS_Variables_List[6], com_func.uint32());

			//just in case, namespace remover
			accparser::replaceAll(*line, caps::caps_ns, "");
		}

		int BackEnd_Parser_Kernel(const char* fnameIn, const char* fnameOut) {
			CUDAFunctions caps_func;
			std::string line;

			fstream finx(fnameIn);
			ofstream foutx("test.cxx");
			while (!finx.eof()) {
				std::getline(finx, line);
				if (line.find("#include", 0) != std::string::npos) continue;
				else foutx << line << endl;
			}
			finx.close();
			foutx.close();

			stringstream ss;
			//TODO get compiler with environment variable
			ss << "g++ -D__CUDACC__ -E test.cxx -o temp.i";
			cout << ss.str();
			std::system(ss.str().c_str());

			remove("test.cxx");

			fstream fin("temp.i");
			ofstream fout(fnameOut);

			if (!fin.good()) return 1;
			if (!fout.good()) return 1;

			while (!fin.eof()) {
				std::getline(fin, line);
				//to delete preprocessor lines
				if (line[0] == '#') continue;
				accparser::replaceAll(line, caps::CAPS_Functions_List[0], caps_func.gr_atidf());
				accparser::replaceAll(line, caps::CAPS_Functions_List[1], caps_func.gr_atidx());
				accparser::replaceAll(line, caps::CAPS_Functions_List[2], caps_func.gr_atidy());
				accparser::replaceAll(line, caps::CAPS_Functions_List[3], caps_func.gr_btidf());
				accparser::replaceAll(line, caps::CAPS_Functions_List[4], caps_func.gr_btidx());
				accparser::replaceAll(line, caps::CAPS_Functions_List[5], caps_func.gr_btidy());
				accparser::replaceAll(line, caps::CAPS_Functions_List[6], caps_func.gr_btnumf());
				accparser::replaceAll(line, caps::CAPS_Functions_List[7], caps_func.gr_btnumx());
				accparser::replaceAll(line, caps::CAPS_Functions_List[8], caps_func.gr_gbidf());
				accparser::replaceAll(line, caps::CAPS_Functions_List[9], caps_func.gr_gbidx());
				accparser::replaceAll(line, caps::CAPS_Functions_List[10], caps_func.gr_gbidy());
				accparser::replaceAll(line, caps::CAPS_Functions_List[11], caps_func.gr_gbnumf());
				accparser::replaceAll(line, caps::CAPS_Functions_List[12], caps_func.gr_gbnumx());
				accparser::replaceAll(line, caps::CAPS_Functions_List[13], caps_func.gr_gbnumy());
				accparser::replaceAll(line, caps::CAPS_Functions_List[14], caps_func.gr_atidminf());
				accparser::replaceAll(line, caps::CAPS_Functions_List[15], caps_func.gr_atidminx());
				accparser::replaceAll(line, caps::CAPS_Functions_List[16], caps_func.gr_atidminy());
				accparser::replaceAll(line, caps::CAPS_Functions_List[17], caps_func.gr_barrier());
				accparser::replaceAll(line, caps::CAPS_Functions_List[18], caps_func.gr_btnumy());

				parse_variable(&line);
				fout << line << endl;
			}

			fin.close();
			fout.close();
			remove("temp.i");
			return 1;
		}
	}
}
