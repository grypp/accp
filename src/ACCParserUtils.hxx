/*
 * ACCParserUtils.hxx
 *
 *  Created on: May 18, 2013
 *      Author: guray ozen
 */

#ifndef ACCPARSERUTILS_HXX_
#define ACCPARSERUTILS_HXX_

#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stack>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <limits>
#include <climits>
using namespace std;
namespace accparser {

	/*	struct MyException: public std::exception {
	 std::string s;
	 MyException(std::string ss) :
	 s(ss) {
	 }
	 const char* what() const throw () {
	 return s.c_str();
	 }
	 };*/

#define DIR_SEPARATOR "/"
	const static string func_start = "extern \"C\" void ";
	const static string func_cuda_start = "extern \"C\" __global__ void ";
	const static string func_main = "main";
	const static string acc_pragma = "#pragma acc";
	const static string omp_task_pragma = "#pragma omp task";
	const static string omp_taskwait_pragma = "#pragma omp taskwait";
	const static string omp_pragma_target = "#pragma omp target";
	const static string omp_pragma = "#pragma omp";
	const static string omp_pragma_for = "#pragma omp for";

	static const int C_LeX_N = 5;
	static const std::string C_LeX[C_LeX_N] = { "for", "if", "else", "while", "do" };

	static const std::string EXT_CXX=".cxx";
	static const std::string EXT_C=".c";
	static const std::string EXT_CUDA=".cu";

	enum DEVICE {
		CUDA, OPENCL
	};

	enum PTYPE {
		KERNEL, GROUPLET, FRONTEND,COMPILEALL
	};

	typedef struct {
		DEVICE target;
		PTYPE parserType;
	} CurrentConfiguration;

	typedef struct {
		struct timeval start;
		struct timeval end;
		double elapsed_time;
	} timing_t;

	void timing_start(timing_t* t);
	void timing_end(timing_t* t);
	double timing_elapsed(const timing_t* t);

	void replaceAll(std::string& str, const std::string& from, const std::string& to);
	std::vector<std::string> split(const std::string &s, char delim);
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

	string getFunction(fstream &fin, const char* funcName);
	string getFunction(fstream &fin, const char* funcName, int maxLine);

	void eraseStringinString(string& str, const string& erased);
	vector<string> parse_function(string ss, string *name);

	char copy_file(const char* source, const char* dest);

	static __inline__ bool searchLineInArray(const string arr[], int n, string line) {
		//todo change with startwith function. firstly use trim
		for (int i = 0; i < n; ++i)
			if (line.find(arr[i], 0) != std::string::npos) return true;
		return false;
	}

	static __inline__ std::string getString_vec(std::vector<string> vec, string delimiter) {
		stringstream ss;
		for (int var = 0; var < vec.size(); ++var)
			ss << vec[var] << delimiter;
		return ss.str().substr(0, ss.str().size() - 1);
	}

	static __inline__ std::string getString_vec_ff(std::vector<string> vec, string delimiter) {
		stringstream ss;
		vector<string> tmp;
		for (int var = 0; var < vec.size(); ++var) {
			tmp = split(vec[var], ' ');
			ss << tmp[tmp.size() - 1] << delimiter;

			//cout << tmp << "\t =====> \t" << split(tmp, ' ').size() << "\t" << split(tmp, ' ')[1] << endl;
		}
		return ss.str().substr(0, ss.str().size() - 1);
	}

	static __inline__ std::string getString_vec(std::vector<string> vec) {
		return getString_vec(vec, "");
	}

	// trim from start
	static __inline__ std::string &ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	// trim from end
	static __inline__ std::string &rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	// trim from both ends
	static __inline__ std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}

#ifndef _WIN32_
#define ERROR_EXEC "ERROR"
	static __inline__ std::string exec_system(const char* cmd) {
	    FILE* pipe = popen(cmd, "r");
	    if (!pipe) return ERROR_EXEC;
	    char buffer[128];
	    std::string result = "";
	    while(!feof(pipe)) {
	    	if(fgets(buffer, 128, pipe) != NULL)
	    		result += buffer;
	    }
	    pclose(pipe);
	    return result;
	}
#endif

}

#endif /* ACCPARSERUTILS_HXX_ */

