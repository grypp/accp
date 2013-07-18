//============================================================================
// Name        : accp.cpp
// Author      : guray ozen
// Version     : 0.1
// Copyright   : openacc integration
// Description : Main in C++, Ansi-style
//============================================================================

#include "CAPSACCGroupletParser.hxx"

/*
 * 1. find grouplet1--> 2
 * 2. write codelet
 * loop
 * 2. find codelet
 * 		1. find configuration			+
 * 		2. find parameters for what ? FE or here?
 * 		2. call kernel
 * 		3. write new file
 */
namespace accp {

	namespace caps {

		ParameterTable codelet_parameters;

		int BackEnd_Parser_Grouplet(const char* fnameIn, const char* fnameOut) {
			fstream fin(fnameIn);
			ofstream fout(fnameOut);
			std::string line, temp;

			if (!fin.good()) return 1;
			std::map<string, CUDAKernel> codeletKernelsTable;

			string grouplet_caller, grouplet;

			fout << "#include <stdio.h>" << endl;
			fout << "#include <cuda.h>" << endl;

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find(accp::caps::caps_init, 0) != std::string::npos) {
					while (!fin.eof()) {
						std::getline(fin, line);
						if (line.find(accp::caps::caps_grouplet, 0) != std::string::npos) {
							string grouplet_arguments;
							for (int i = 0; i != line.length(); i++)
								if (line[i] == '(' && line[i + 1] == '"') {
									grouplet_arguments = line.substr(i + 1);
									grouplet_arguments = grouplet_arguments.substr(0, grouplet_arguments.length() - 2);
									break;
								}
							vector<string> gparameters = accp::split(grouplet_arguments, ',');
							grouplet_caller = gparameters[0].substr(1, gparameters[0].length() - 2);
#ifdef DEBUG
							cout << "Grouplet_Arguments found :\t" << grouplet_arguments << endl;
							cout << "Grouplet_Caller found :\t\t" << grouplet_caller << endl;
#endif
							break;
						}
					}
					break;
				}
			}

			//to rereading
			fin.seekg(0, std::ios::beg);
			grouplet_caller += "("; //FIXME performance? re-create string object?

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find(grouplet_caller, 0) != std::string::npos) {
					std::getline(fin, line);
					if (line.find("{", 0) != std::string::npos) {
						std::getline(fin, line);
						vector<string> vec = split(line, '(');
						grouplet = vec[1];
						break;
					}
				}

			}

#ifdef DEBUG
			cout << "Grouplet found :\t\t" << grouplet << endl;
#endif
			string grouplet_sign;
			stringstream grouplet_fnc;
			vector<string> codelet;
			int bracketCounter = 1;

			fin.seekg(0, std::ios::beg);

			//TODO Implement multiple codelet caller
			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find(grouplet, 0) != std::string::npos) {
					vector<string> temp_parameters_val;
					string glob_parameter;
					string gsign = line;

					std::getline(fin, line);
					if (line.find("{", 0) != std::string::npos) {
						//grouplet signer
						parse_variable(&gsign);
						vector<string> params = split(gsign, '(');
						if (params.size() != 2) {
							fprintf(stderr, "ERROR: %s", "PARSER: parameter size bigger than 2");
							return 1;
						}
						gsign = params[1].substr(0, params[1].size() - 1);
						params = accp::split(gsign, ',');
						vector<string> temp_codParams;
						for (int var = 0; var < params.size(); ++var) {
							if (params[var].find(accp::caps::caps_devptr, 0) != std::string::npos) {
								replaceAll(params[var + 1], ">", "*");
								temp_codParams.push_back(params[var + 1]);
								var++;
							} else temp_codParams.push_back(params[var]);
						}

						grouplet_sign = "extern \"C\" void " + grouplet + '(' + getString_vec(temp_codParams, ",") + ')';
						//grouplet signer
						CUDAKernel currentKernel;
						currentKernel.dynamicMemSize = "0";
						while (!fin.eof()) {
							std::getline(fin, line);
							//todo add and look ignored function
							if (line.find("__hmppcg_call.addSharedParameter", 0) != std::string::npos) continue;
							else if (line.find(accp::caps::grid_size_x, 0) != std::string::npos) {
								for (int i = 0; i != line.length(); i++) {
									if (line[i] == '(') {
										string test = line.substr(i + 1);
										currentKernel.sizeX = test.substr(0, test.length() - 2);
										parse_variable(&currentKernel.sizeX);
										break;
									}
								}
							} else if (line.find(accp::caps::grid_size_y, 0) != std::string::npos) {
								for (int i = 0; i != line.length(); i++) {
									if (line[i] == '(') {
										string test = line.substr(i + 1);
										currentKernel.sizeY = test.substr(0, test.length() - 2);
										parse_variable(&currentKernel.sizeY);
										break;
									}
								}
							} else if (line.find(accp::caps::block_size_x, 0) != std::string::npos) {
								for (int i = 0; i != line.length(); i++) {
									if (line[i] == '(') {
										string test = line.substr(i + 1);
										currentKernel.blockX = test.substr(0, test.length() - 2);
										parse_variable(&currentKernel.blockX);
										break;
									}
								}
							} else if (line.find(accp::caps::block_size_y, 0) != std::string::npos) {
								for (int i = 0; i != line.length(); i++) {
									if (line[i] == '(') {
										string test = line.substr(i + 1);
										currentKernel.blockY = test.substr(0, test.length() - 2);
										parse_variable(&currentKernel.blockY);
										break;
									}
								}
							} else if (line.find(accp::caps::addParameter, 0) != std::string::npos) {
								for (int i = 0; i != line.length(); i++) {
									if (line[i] == '(') {
										string test = line.substr(i + 1);
										test = test.substr(0, test.size() - 2);
										parse_variable(&test);
										vector<string> params = split(test, ',');
										stringstream ss;
										if (params.size() == 2) temp_parameters_val.push_back(params[0]);
										else temp_parameters_val.push_back(params[0].substr(1));
										break;
									}
								}
							} else if (line.find(accp::caps::caps_codelet_launch, 0) != std::string::npos) {
								for (int i = 0; i != line.length(); i++) {
									if (line[i] == '(') {
										string test = line.substr(i + 1);
										test = test.substr(0, test.length() - 2);
										codelet.push_back(accp::split(test, ',')[0]);
										codeletKernelsTable[accp::split(test, ',')[0]] = currentKernel;

										int var = codelet.size() - 1;
										grouplet_fnc << "\t" << "dim3 numBlocks" << var << "(" << codeletKernelsTable[codelet[var]].sizeX << "," << codeletKernelsTable[codelet[var]].sizeY << ");" << endl;
										grouplet_fnc << "\t" << "dim3 threadsPerBlock" << var << "(" << codeletKernelsTable[codelet[var]].blockX << "," << codeletKernelsTable[codelet[var]].blockY << ");" << endl;

										if (codeletKernelsTable[codelet[var]].dynamicMemSize == "0") grouplet_fnc << "\t" << codelet[var] << "<<<numBlocks" << var << ",threadsPerBlock" << var << ">>>(";
										else grouplet_fnc << "\t" << codelet[var] << "<<<numBlocks" << var << ",threadsPerBlock" << var << "," << codeletKernelsTable[codelet[var]].dynamicMemSize << ">>>(";

										string params = getString_vec_ff(temp_parameters_val, ",");
										replaceAll(params, glob_parameter, "__hmpp_addr__" + glob_parameter);
										grouplet_fnc << params;
										grouplet_fnc << ");" << endl << endl;
										temp_parameters_val.clear();
										break;
									}
								}
							} else if (line.find("hmpprt::", 0) != std::string::npos) {
								if (line.find("hmpprt::DevicePtr<hmpprt::MS_CUDA_GLOB", 0) != std::string::npos) {
									string type;
									vector<string> devptr = split(line, ',');
									for (int k = 0; k < devptr.back().size(); ++k) {
										if (devptr.back()[k] == '>') break;
										else type += (devptr.back()[k]);
									}
									accp::caps::parse_variable(&type);
									grouplet_fnc << "\t" << type << "*" << split(line, '>').back() << endl;
									glob_parameter = split(line, '>').back();
									replaceAll(glob_parameter, ";", "");
									trim(glob_parameter);
								} else if (line.find("hmpprt::DevicePtr<hmpprt::MS_CUDA_SHARED", 0) != std::string::npos) {
									std::getline(fin, line);
									currentKernel.dynamicMemSize = split(split(line, ',').back(), ')').front();
								}
								// hmpprt::Context::getInstance()->allocate((void **) (&i_3), hmpprt::MS_CUDA_GLOB, 4);
								/*else if (line.find("hmpprt::Context::getInstance()->allocate", 0) != std::string::npos) {
								 grouplet_fnc << "\tcudaMalloc(";
								 grouplet_fnc << split(line.substr(line.find("(void **)", 0)), ',')[0] << ",";
								 grouplet_fnc << split(line.substr(line.find("(void **)", 0)), ',')[2] << endl;

								 }*/
								//FIXME
								//hmpprt::Context::getInstance()->free((void **) (&i_2));
								//else if (line.find("hmpprt::Context::getInstance()->free", 0) != std::string::npos) {
								//	grouplet_fnc << "\tcudaFree(";
								//	grouplet_fnc << line.substr(line.find("(void **)", 0)) << endl;
								//}

								//FIXME already added. Analyze after this case
								else {
									string tmp = line;
									parse_variable(&tmp);
									replaceAll(line, caps::caps_ns, "");
									if (line.find(tmp, 0) == std::string::npos) grouplet_fnc << tmp << endl;
								}

							} else if (line.find("#", 0) != std::string::npos) continue;
							else if (line.find("=", 0) == std::string::npos) grouplet_fnc << line << endl;

							if (line.find("}", 0) != std::string::npos) bracketCounter--;
							else if (line.find("{", 0) != std::string::npos) bracketCounter++;
							if (bracketCounter == 0) break;
						}
						break; //to exit grouplet
					}
				}
			}

			fin.close();
			fin.open(fnameIn);
			for (int var = 0; var < codelet.size(); ++var) {
				while (!fin.eof()) {
					std::getline(fin, line);
					if (line.find(codelet[var], 0) != std::string::npos) {
						if (line.find("__global__", 0) != std::string::npos) {
							parse_variable(&line);
							fout << line << ";" << endl;
							break;
						}
					}
				}
				fin.seekg(0, std::ios::beg);
			}
			fout << endl;
			fout << grouplet_sign << endl;
			fout << "{" << endl;
			fout << grouplet_fnc.str() << endl;

			fin.close();
			fout.close();
			return 0;
		}
	}
}

