#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include "IPData.h"
#include <regex>
using namespace std;
class IPPinger
{
public:
	////from stackoverflow  http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c-using-posix
	static std::string exec(const char* cmd) 
	{  
		char buffer[128];
		std::string result = "";
		std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
		if (!pipe) throw std::runtime_error("popen() failed!");
		while (!feof(pipe.get())) {
			if (fgets(buffer, 128, pipe.get()) != NULL)
				result += buffer;
		}
		return result;
	}

	static void setResp(vector<IPData>& ips)
	{
		int i = 1;
		int siz = ips.size();
		for (auto &ip : ips)
		{
			cout << i++ << "/" << siz;
			string resp = exec(("ping -n 1 -l 32 " + ip.IP).c_str());
			regex reg("(Average = )");
			smatch m;
			regex_search(resp, m, reg);
			resp = m.suffix().str();
			int avgres = strtol(resp.c_str(), nullptr, 10);
			ip.avgRes = avgres;
			cout <<"\t"<<ip.IP<<':'<<ip.port<<"\t"<<ip.avgRes << endl;
		}
	}
};