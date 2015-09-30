//第一天
//求平方根代码

#include "stdafx.h"
#include <iostream>
#include <cmath>

int _tmain(int argc, _TCHAR* argv[])
{

	using namespace std; 

	double area;
	cout << "Enter the floor area, in square feet, of your home: ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "That's the equivalent of a square " << side
		<< " feet to the side." << endl;
	cout << "How fascinating!" << endl;

	
	cin.get();
	cin.get();
	return 0;
}
