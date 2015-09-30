#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
void old_mul_12(void);
int _tmain(int argc, _TCHAR* argv[])
{

	old_mul_12();

	cin.get();
	cin.get();
	return 0;
}

void old_mul_12(void)
{
	cout << "Please input your old: " << endl;
	int old;
	cin >> old;
	cout << "You month include " << old * 12 << " months!" << endl;
}
