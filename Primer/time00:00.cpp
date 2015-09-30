//第二天
//输入小时和分钟，在main()函数中，将这两个值传递给一个void函数，显示成 (Time: 9:28)括号中的样子
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

void time(int H, int M);

int _tmain(int argc, _TCHAR* argv[])
{



	cout << "Enter the number of hours: ";
	int h;
	cin >> h;

	cout << "Enter the number of minutes: ";
	int m;
	cin >> m;

	time(h, m);

	cin.get();
	cin.get();
	return 0;
}

void time(int H, int M)
{
	cout << "Time: " << H << ":" << M;

}
