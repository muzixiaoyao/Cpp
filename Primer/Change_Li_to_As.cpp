//第二天
//将光年转换成天文单位
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double Change_Li_to_As(double Li);					//参数Li为光年，返回值为天文单位

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter the number of light years: ";
	double l;
	cin >> l;
	double a = Change_Li_to_As(l);
	cout << l << " light years = " << a << " astronomical units.";


	cin.get();
	cin.get();
	return 0;
}

double Change_Li_to_As(double Li)
{
	double as = Li * 63240;
	return as;
}
