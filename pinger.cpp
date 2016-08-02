#include <iostream>
#include <Windows.h>
#include "IPExtractor.h"
#include <vector>
#include "IPPinger.h"
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	vector<IPData> v;
	IPExtractor ipe("data.txt");
	ipe.extract(v);
	IPPinger::setResp(v);
	sort(v.begin(), v.end());
	int i = 1;
	ofstream out("out.txt", ios::out);
	for (auto x : v)
	{
		out <<setw(5)<<left<< i++ << x << " -  " << x.avgRes <<" ms"<< endl;
	}
	
}