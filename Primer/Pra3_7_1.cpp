#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int in1;
	cout << "Enter your height in inch:_____\b\b\b\b\b";
	cin >> in1;
	const int inch_to_feet = 12;
	int feet = in1 / inch_to_feet;
	int in2 = in1 / inch_to_feet;
	cout << in1 << " inch is " << feet << " feet, "
		 << in2 << "inch." << endl;
	return 0;
}
