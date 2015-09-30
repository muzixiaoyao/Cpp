//第一天
//程序清单2.5
#include "stdafx.h"
#include <iostream>
#include <cmath>

void simon(int n);

int _tmain(int argc, _TCHAR* argv[])
{

	using namespace std; 

	simon(3);
	cout << "Pick an integer: ";
	int count;
	cin >> count;
	simon(count);
	cout << "Done!" << endl;
	
	cin.get();
	cin.get();
	return 0;
}

void simon(int n)
{
	using namespace std;
	cout << "Simon say touch your toes " << n << " times." << endl;
}
