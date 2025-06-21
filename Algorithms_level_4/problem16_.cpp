#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

struct stDate
{
	short Year=0, Month=0, Day=0;
};
stDate ReadDate()
{
	stDate Date;
	Date.Day = InputLib::ReadNumber("a Day");
	Date.Month = InputLib::ReadNumber("a Month");
	Date.Year = InputLib::ReadNumber("a Year");
	return Date;
}
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
bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == DaysInMonth(Date.Year, Date.Month);
}
bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{	
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
		Date.Day++;
	return Date;
}

int main()
{
	stDate Date = ReadDate();
	Date = IncreaseDateByOneDay(Date);
	cout << "Date after Adding one day is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}
