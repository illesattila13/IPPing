#include "IPData.h"
#include <iomanip>

ostream & operator<<(ostream & os, IPData & ip)
{
	{
		os <<setw(16)<<right<< ip.IP << ":" <<setw(3)<< ip.port;
		return os;
	}
}
