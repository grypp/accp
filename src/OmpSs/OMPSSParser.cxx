/*
 * OMPSSParser.cxx
 *
 *  Created on: May 24, 2013
 *      Author: grypp
 */

#include <stdio.h>
#include "OMPSSParser.hxx"

namespace accparser {
	namespace ompss {

		void OmpSs_Parser(const char* fnameIn, const char* fnameOut, const char* fnameEx,bool removeFile) {
			const char* fname_acc_x = "acc.x";
			const char* fname_ompss_c = "ompss.c";
			fstream fin(fnameIn);
			ofstream fout(fnameOut);
			string line;

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find("#pragma", 0) != std::string::npos) {
					if (line.find("device(acc/cuda)", 0) != std::string::npos) {
						accparser::replaceAll(line, "copy_inout(", "copy(");
						accparser::replaceAll(line, "copy_in(", "copyin(");
						accparser::replaceAll(line, "copy_in(", "create(");
						accparser::replaceAll(line, "copy_out(", "copyout(");
						//TODO only kernels!
						accparser::replaceAll(line, "omp target device(acc/cuda)", "acc kernels");

						fout << line << endl;

					} else continue;
				} else fout << line << endl;
			}
			fout.close();
			fin.close();

			//----------------------------------compile with HMPP--------------------------
			string _command;
			_command.reserve(100);
			_command.append("hmpp -kk -d2 gcc ");
			_command.append(fnameOut);
			_command.append(" -o ");
			_command.append(fname_acc_x);
			accparser::exec_system(_command.c_str());
			//----------------------------------compile with HMPP--------------------------

			//----------------------------------compile with OmpSs-------------------------
			//TODO only CAPS!!
			string front_end_name = accparser::exec_system("ls -rt *.translated.i");
			trim(front_end_name);
			cout << fnameIn << "  " << fname_ompss_c << "  " << front_end_name << endl;
			FrontEnd_Parser_internal(fnameIn, fname_ompss_c, front_end_name.c_str());

			//TODO only *.cu files!!!!!
			vector<string> backend_files = split(accparser::exec_system("ls *.cu"), '\n');
			_command.clear();
			_command.reserve(500);
			_command.append("mnvcc --ompss ");
			_command.append(fname_ompss_c);
			char kernel[100], grouplet[100];
			for (int i = 0; i < backend_files.size(); ++i) {
				sprintf(kernel, "kernel%d.cu", i);
				sprintf(grouplet, "grouplet%d.cu", i);
				accparser::caps::BackEnd_Parser_Kernel(backend_files[i].c_str(), kernel);
				accparser::caps::BackEnd_Parser_Grouplet(backend_files[i].c_str(), grouplet);
				_command.append(" ");
				_command.append(kernel);
				_command.append(" ");
				_command.append(grouplet);
			}
			_command.append(" ");
			_command.append("-o");
			_command.append(" ");
			_command.append(fnameEx);

			accparser::exec_system(_command.c_str());

			remove(fname_acc_x);
			remove(fnameOut);
			accparser::exec_system("rm accp_tmp_*");
			accparser::exec_system("rm __*");
			if (removeFile) {
				for (int i = 0; i < backend_files.size(); ++i) {
					sprintf(kernel, "kernel%d.cu", i);
					sprintf(grouplet, "grouplet%d.cu", i);
					remove(kernel);
					remove(grouplet);
				}
				remove(fname_ompss_c);
			}
		}

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

		int FrontEnd_Parser_internal(const char* fnameIn, const char* fnameOut, const char* fnameFE) {
			//fin is OmpSs file!!!!
			fstream fin(fnameIn), finFE(fnameFE);
			ofstream fout(fnameOut);
			stringstream ss, ss_sign;
			string line;
			vector<string> grouplets;

			if (!fin.good()) return -1;
			if (!finFE.good()) return -1;
			if (!fout.good()) return -1;

			while (!finFE.eof()) {
				std::getline(finFE, line);
				if (line.find(accparser::func_main, 0) != std::string::npos) break;
			}

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find(accparser::omp_target_pragma, 0) != std::string::npos) {
					accparser::replaceAll(line, "device(acc/cuda)", "device(cuda)");
					ss << line << endl;
				} else if (line.find(accparser::omp_task_pragma, 0) != std::string::npos && line.find(accparser::omp_taskwait_pragma, 0) == std::string::npos) {

					ss << line << endl;

					//that's function remover!!!
					line = removeBracket(fin);
					while (accparser::searchLineInArray(C_LeX, C_LeX_N, line))
						line = removeBracket(fin);

					//that's function adder!!!
					ss << accparser::caps::FrontEnd_Parser(finFE, &line) << endl;
					grouplets.push_back(line);

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

