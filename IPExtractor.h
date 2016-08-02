#ifndef IPEXTR
#define IPEXTR
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include "IPData.h"
#include <vector>

using namespace std;

/**
This class extracts ip adressis from a txt file and put them into a container.
*/
class IPExtractor
{
	string target;

public:
	/**
	The ctor sets the input filestream.
	*/
	IPExtractor(const char *ifilename);

	void extract(vector<IPData>& ipDatas);
	
};

#endif //IPEXTR