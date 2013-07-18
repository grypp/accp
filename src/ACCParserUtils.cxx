/*
 * accpUtils.cpp
 *
 *  Created on: May 18, 2013
 *      Author: guray ozen
 */

#include "accpUtils.hxx"

namespace accp {

	string getFunction(fstream &fin, const char* funcName) {
		return getFunction(fin, funcName, std::numeric_limits<int>::max());
	}

	string getFunction(fstream &fin, const char* funcName, const char* funcName2) {
		string line, function;
		while (!fin.eof()) {
			std::getline(fin, line);
			if (line.find(funcName, 0) != std::string::npos || line.find(funcName2, 0) != std::string::npos) {
				if (line.find(';', 0) != std::string::npos) return line;
				function.reserve(line.size() + 100);
				function.append(line);
				int i = 1;
				while (!fin.eof()) {
					i++;
					std::getline(fin, line);
					//for preprocessor line
					if (line[0] == '#') continue;
					function.append(line);
					if (line.find(";", 0) != std::string::npos) break;
				}
				break;
			}
		}
		return function;
	}

	/*
	 * get function caller. Or signature
	 */
	string getFunction(fstream &fin, const char* funcName, int maxLine) {
		string line, function;
		while (!fin.eof()) {
			std::getline(fin, line);
			if (line.find(funcName, 0) != std::string::npos) {
				if (line.find(';', 0) != std::string::npos) return line;
				function.reserve(line.size() + 100);
				function.append(line);
				int i = 1;
				while (!fin.eof()) {
					if (maxLine == i) return function;
					i++;
					std::getline(fin, line);
					//for preprocessor line
					if (line[0] == '#') continue;
					function.append(line);
					if (line.find(";", 0) != std::string::npos) break;
				}
				break;
			}
		}
		return function;
	}

	void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty()) return;
		std::size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}

	void eraseStringinString(string& str, const string& erased) {
		int tmpBracketCounter = 1, end = 0;
		if (str.find(erased, 0) != std::string::npos) {
			for (int k = str.find(erased, 0) + erased.size() + 1; k != str.size(); k++) {
				if (tmpBracketCounter == 0) break;
				if (str[k] == '(') tmpBracketCounter++;
				else if (str[k] == ')') tmpBracketCounter--;
				else end++;
			}
			end += erased.size() + 3;
			str.erase(str.find(erased, 0), end);
		}
	}

	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	std::vector<std::string> split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}

	void timing_start(timing_t* t) {
		memset(t, 0, sizeof(*t));
		gettimeofday(&(t->start), NULL);
	}

	void timing_end(timing_t* t) {
		gettimeofday(&(t->end), NULL);

		double start_value = t->start.tv_sec * 1e6 + t->start.tv_usec;
		double end_value = t->end.tv_sec * 1e6 + t->end.tv_usec;

		double diff_value = end_value - start_value;

		t->elapsed_time = diff_value / 1e6;
	}

	double timing_elapsed(const timing_t* t) {
		return (t->elapsed_time);
	}

	char copy_file(const char* source, const char* dest) {
		// Plain old copy
		FILE* orig_file = fopen(source, "r");
		if (orig_file == NULL) return -1;

		FILE* dest_file = fopen(dest, "w");

		if (dest_file == NULL) {
			fclose(orig_file);
			return -1;
		}

#define BLOCK_SIZE 1024
		char c[BLOCK_SIZE];
		int actually_read = fread(c, sizeof(char), BLOCK_SIZE, orig_file);

		while (actually_read != 0) {
			int actually_written = fwrite(c, sizeof(char), actually_read, dest_file);
			if (actually_written < actually_read) {
				fclose(dest_file);
				fclose(orig_file);
				return -1;
			}
			actually_read = fread(c, sizeof(char), BLOCK_SIZE, orig_file);
		}
#undef BLOCK_SIZE
		if (feof(orig_file)) {
			// Everything is OK
			clearerr(orig_file);
		} else if (ferror(orig_file)) {
			// Something went wrong
			fclose(dest_file);
			fclose(orig_file);
			return -1;
		}

		fclose(orig_file);
		fclose(dest_file);
		return 0;
	}

#if 0
	//sample function
	openacci_enter_region(
			/* file_name    = */"vecadd.c",
			/* line_number  = */34,
			/* region_kind  = */& (a)[0] /* kernels */,
			/* num_args     = */sizeof (a)[0],
			/* async_mode   = */0 /* SYNC */,
			/* queue   	  = */0 /* meaningless */);
#endif

	//ss = function string
	//name = name
	vector<string> parse_function(string ss, string *name) {
		std::vector<std::string> vec;

		int pos = ss.find('(', 0);
		if (pos == std::string::npos) {
			cout << "function is empty " << endl;
			exit(-1);
		}

		vector<string> tmp = split(ss.substr(0, pos), ' ');
		*name = tmp[tmp.size() - 1];
		tmp.clear();

		string tmp_after_name = ss.substr(pos + 1, ss.size());

		//comment clear
		string commentless;

		if (tmp_after_name.find("/*", 0) != std::string::npos) {
			commentless.reserve(tmp_after_name.size());
			bool isComment = false;
			int lastIndex = 0;
			trim(tmp_after_name);

			for (int i = 0; i < tmp_after_name.length() - 1; ++i)
				if (tmp_after_name[i] == '/' && tmp_after_name[i + 1] == '*') {
					isComment = true;
					commentless.append(tmp_after_name.substr(lastIndex, i - lastIndex));
				} else if (tmp_after_name[i] == '*' && tmp_after_name[i + 1] == '/' && isComment) {
					isComment = false;
					lastIndex = i + 2;
				}

			if (lastIndex < tmp_after_name.size() && !isComment) commentless.append(tmp_after_name.substr(lastIndex, tmp_after_name.size() - lastIndex));
			trim(commentless);
			if (commentless[commentless.size() - 1] == ';' && commentless[commentless.size() - 2] == ')') commentless = commentless.substr(0, commentless.size() - 2);

		} else commentless = tmp_after_name;

		tmp = split(commentless, ',');
		for (int i = 0; i < tmp.size(); ++i) {
			if (tmp[i].find("<", 0) != std::string::npos) {
				vec.push_back(tmp[i] + tmp[i + 1]);
				i++;
			} else vec.push_back(tmp[i]);
		}

		return vec;
	}

}
