#ifndef IPDATA
#define IPDATA
#include <string>
#include <iostream>

using namespace std;

class IPData
{
public:
	string IP;
	string port;
	int avgRes;

	IPData(string ip, string port) : IP(ip), port(port), avgRes(-1) {}

	bool operator<(IPData& rhs)
	{
		if (avgRes == -1)
			return IP < rhs.IP;
		else
			return avgRes < rhs.avgRes;
	}


};

ostream& operator<<(ostream& os, IPData& ip);


#endif //IPDATA