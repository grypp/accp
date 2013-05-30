//============================================================================
// Name        : ACCParser.cpp
// Author      : guray ozen
// Version     : 0.1
// Copyright   : openacc integration
// Description : Main in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <map>

#include "ACCParserUtils.hxx"
#include "CUDAFunctions.hxx"
#include "KernelFunctions.hxx"

#include "Providers/CAPSACCRuntimeConst.hxx"
#include "Providers/CAPSACCKernelParser.hxx"
#include "Providers/CAPSACCGroupletParser.hxx"
#include "OmpSs/OMPSSParser.hxx"

using namespace std;
using namespace accparser;
using namespace caps;
using namespace ompss;

//============================================================================
#define VERSION 0.1
//============================================================================
#define HELP_STRING \
"Options: \n" \
"  -h		                Shows this help and quits\n" \
"  -v		                Shows version and quits\n" \
"  -i		                Input file for Back-End or Front-End\n" \
"  -o		                Output file\n" \
"  -g/k			        Parser Type Backend for Grouplet/Kernel (g/k)\n" \
"  -f			        Input file that is called translated bt openACC for parser Type Frontend \n" \
"\n"
//============================================================================

char *input, *output, *output_temp = "temp.cxx", *input_2;
PTYPE type;

void cl_parse(int argc, char* argv[]) {
//accp -i imput.cxx -o output.cu

	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'v') {
				cout << VERSION <<endl;
				exit(1);
			} else if (argv[i][1] == 'h') {
				cout << HELP_STRING << endl;
				exit(1);
			} else if (argv[i][1] == 'i') input = argv[i + 1];
			else if (argv[i][1] == 'o') output = argv[i + 1];
			else if (argv[i][1] == 'g') type = GROUPLET;
			else if (argv[i][1] == 'k') type = KERNEL;
			else if (argv[i][1] == 'f') {
				type = FRONTEND;
				input_2 = argv[i + 1];
			}
		}
	}

	if (argc < 5) {
		fprintf(stderr, HELP_STRING);
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	accparser::timing_t timing_global;
	accparser::timing_start(&timing_global);

	cl_parse(argc, argv);

	switch (type) {
		case KERNEL:
			accparser::copy_file(input, output_temp);
			accparser::caps::BackEnd_Parser_Kernel(output_temp, output);
			break;
		case GROUPLET:
			accparser::caps::BackEnd_Parser_Grouplet(input, output);
			break;
		case FRONTEND:
			accparser::ompss::FrontEnd_Parser(input, output, input_2);
			break;
		default:
			break;
	}

	accparser::timing_end(&timing_global);
	cout << endl << "Elapsed Time \t" << accparser::timing_elapsed(&timing_global) << endl;
	return 0;
}
