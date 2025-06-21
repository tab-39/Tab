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

int DaysInMonth(int Year, int Month)
{
	if (Month < 1 || Month > 12)
		return 0;
	short arr31Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return (Month == 2 && IsLeapYear(Year))? 29 : arr31Days[Month-1];
}

int CountingDays(int Year, int Month, int Day)
{
	int Counter = 0;
	for (int i = 1; i < Month; i++)
	{
		Counter += DaysInMonth(Year, i);
	}
	Counter += Day;
	return Counter;
}

int main()
{
	int Year = InputLib::ReadNumber("a Year");
	int Month = InputLib::ReadNumber("a Month");
	int Day = InputLib::ReadNumber("a Day");
	cout << "Number of Days from the beginning of the year is: " << CountingDays(Year, Month, Day);
	return 0;
}
