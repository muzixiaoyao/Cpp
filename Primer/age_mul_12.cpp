//第二天
//输入年龄，显示该年龄包含了多少个月份
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
void age_mul_12(void);
int _tmain(int argc, _TCHAR* argv[])
{

	age_mul_12();

	cin.get();
	cin.get();
	return 0;
}

void age_mul_12(void)
{
	cout << "Please input your age: " << endl;
	int old;
	cin >> old;
	cout << "You month include " << old * 12 << " months!" << endl;
}
