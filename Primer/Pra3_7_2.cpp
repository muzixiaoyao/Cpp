//以磅为单位输入体重，以几英尺几英寸的方式输入身高,然后将身高和体重转换为米和千克，体重除以身高 的平方就是BMI

#include <iostream>
#include <cmath>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	double pound,kg,inch,feet,meter; 		//kg为身高，inch是英寸，feet为英尺
	const int feet_to_inch = 1/12;
	const double inch_to_meter = 0.0254;
	const double pound_to_kg = 1/2.2;
	cout << "Please input your herght(feet, inch): " << endl;
	cin >> feet;
	cin >> inch;
	cout << "Please input your pound: " << endl;
	cin >> pound;
	meter = (feet / feet_to_inch + inch) * inch_to_meter;
	kg = pount * pound_to_kg;
	double bmi;
	bmi = sqrt(kg / meter);
	cout << "You BMI value is: "; << bmi << endl;
	return 0;
	
}
