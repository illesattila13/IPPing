#include "IPExtractor.h"
#include <iterator>

IPExtractor::IPExtractor(const char * ifilename) 
{
	ifstream inputFile(ifilename);
	char c;
	while (inputFile >> c)
	{
		target += c;
	}
}

void IPExtractor::extract(vector<IPData>& ipDatas)
{
	smatch match;
	regex reg("\\\"([0-9]{1,3}\\.){3}[0-9]{1,3}\\:[0-9]{1,3}"); //matches ip:port (12.36.1.258:241) 2



	while (regex_search(target, match, reg))
	{
		string m = match.str();
		size_t pos = m.find(':');
		string ip(m.begin() + 1, m.begin() + pos);
		string port(m.begin() + pos + 1, m.end());
		ipDatas.emplace_back(ip, port);


		target = match.suffix().str();
	}
}
