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
	if (YearNumber % 400 == 0)
	{
		return true;
	}
	else if (YearNumber % 4 == 0 && YearNumber % 100 != 0)
	{
		return true;
	}
	return false;
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