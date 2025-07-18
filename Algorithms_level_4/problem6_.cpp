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

int DaysInMonth(int Month, int Year)
{
	if (Month < 1 || Month > 12)
		return 0;
	short arr31Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return (Month == 2 && IsLeapYear(Year))? 29 : arr31Days[Month-1];
}

int HoursInMonth(int Month, int Year)
{
	return DaysInMonth(Month, Year) * 24;
}

int MinutesInMonth(int Month, int Year)
{
	return HoursInMonth(Month, Year) * 60;
}

int SecondsInMonth(int Month, int Year)
{
	return MinutesInMonth(Month, Year) * 60;
}

int main()
{
	int Year = InputLib::ReadNumber("Year to check");
	int Month = InputLib::ReadNumber("Month to check");
	cout << "Number of Days    " << "in Month [" << Month <<  "] is " << DaysInMonth(Month, Year) << endl;
	cout << "Number of Hours   " << "in Month [" << Month <<  "] is " << HoursInMonth(Month, Year) << endl;
	cout << "Number of Minutes " << "in Month [" << Month <<  "] is " << MinutesInMonth(Month, Year) << endl;
	cout << "Number of Seconds " << "in Month [" << Month <<  "] is " << SecondsInMonth(Month, Year) << endl;
	return 0;
}
