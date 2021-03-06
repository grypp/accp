//============================================================================
// Name        : accp.cpp
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
#include "codegen/cuda/cudagen.hxx"

using namespace std;
using namespace accp;
using namespace caps;
using namespace ompss;
using namespace codegen;


//============================================================================
#define VERSION 0.1
//============================================================================
#define HELP_STRING \
"Default usage: accp inputfile.cpp -o output.x \n" \
"Options: \n" \
"  -h		                Shows this help and quits\n" \
"  -v		                Shows version and quits\n" \
"  -k		                Keep translated and extracted files\n" \
"  -o		                Output file\n" \
"  -g			        Parser Type Backend for Grouplet\n" \
"  -w			        Parser Type Backend for Kernel\n" \
"  -f			        Input file that is called translated bt openACC for parser Type Frontend \n" \
"  -p			        compiler parameters \n" \
"\n"
//============================================================================

char *input, *output, *output_temp = "accp_tmp.c", *input_2;
PTYPE type;

bool removeFile = true;
string CPPFLAGS;
void cl_parse(int argc, char* argv[]) {
	type = COMPILEALL;
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'k') {
				removeFile = false;
			} else if (argv[i][1] == 'p') {
				CPPFLAGS = argv[i + 1];
				i++;
			} else if (argv[i][1] == 'v') {
				cout << VERSION <<endl;
				exit(1);
			} else if (argv[i][1] == 'h') {
				cout << HELP_STRING << endl;
				exit(1);
			} else if (argv[i][1] == 'o') {
				output = argv[i + 1];
				i++;
			} else if (argv[i][1] == 'g') type = GROUPLET;
			else if (argv[i][1] == 'w') type = KERNEL;
			else if (argv[i][1] == 'f') {
				type = FRONTEND;
				input_2 = argv[i + 1];
			}
		} else input = argv[i];
	}

	if (argc < 4) {
		fprintf(stderr, HELP_STRING);
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	accp::ompss::FrontEnd_Parser_internal(input, output, input_2);

	accp::timing_t timing_global;
	accp::timing_start(&timing_global);

	cl_parse(argc, argv);

	switch (type) {
		case KERNEL:
			accp::copy_file(input, output_temp);
			accp::caps::BackEnd_Parser_Kernel(output_temp, output);
			break;
		case GROUPLET:
			accp::caps::BackEnd_Parser_Grouplet(input, output);
			break;
		case FRONTEND:
			//accp::ompss::FrontEnd_Parser(input, output, input_2);
			cout << input << " 2: " << input_2 << endl;
			accp::ompss::FrontEnd_Parser_internal(input, output, input_2);
			break;
		case COMPILEALL:
			accp::ompss::OmpSs_Parser(input, output_temp, output, removeFile,CPPFLAGS);
			break;
		default:
			break;
	}

	accp::timing_end(&timing_global);
	cout << endl << "Elapsed Time \t" << accp::timing_elapsed(&timing_global) << endl;
	return 0;
}
