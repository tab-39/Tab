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

int DaysInYear(int Year)
{
	return IsLeapYear(Year)?  366 : 365;
}

int HoursInYear(int Year)
{
	return IsLeapYear(Year)?  8784 : 8760;
}

int MinutesInYear(int Year)
{
	return IsLeapYear(Year)?  527040 : 525600;
}

int SecondsInYear(int Year)
{
	return IsLeapYear(Year)?  31622400 : 31536000;
}

int main()
{
	int Year = InputLib::ReadNumber("Year to check");
	cout << "Number of Days    " << "in Year [" << Year <<  "] is " << DaysInYear(Year) << endl;
	cout << "Number of Hours   " << "in Year [" << Year <<  "] is " << HoursInYear(Year) << endl;
	cout << "Number of Minutes " << "in Year [" << Year <<  "] is " << MinutesInYear(Year) << endl;
	cout << "Number of Seconds " << "in Year [" << Year <<  "] is " << SecondsInYear(Year) << endl;
	return 0;
}
