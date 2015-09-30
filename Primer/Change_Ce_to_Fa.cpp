//第二天
//转换摄氏度为华氏度
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
float Change_Ce_to_Fa(float Ce);
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please enter a Celsius value: ";
	float C;
	cin >> C;
	float F = Change_Ce_to_Fa(C);
	cout << C << " degrees Celsius is " << F << "degrees Fahrenheit.";


	cin.get();
	cin.get();
	return 0;
}

float Change_Ce_to_Fa(float Ce)
{
	float Fa = 1.8 * Ce + 32.0;
	return Fa;
}
