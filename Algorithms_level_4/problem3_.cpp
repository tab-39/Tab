#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

bool IsLeapYear(int YearNumber)
{
	return YearNumber % 400 == 0 || (YearNumber % 4 == 0 && YearNumber % 100 != 0);
}

int main()
{
	int Year = InputLib::ReadNumber("Year to text");
	if (IsLeapYear(Year))
	{
		cout << "Yes, It is a leap year!";
	}
	else
	{
		cout << "No, It is not leap Year!";
	}
	return 0;
}