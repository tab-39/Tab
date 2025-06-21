#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

enum enDateCompare { Before = -1, Equal = 0, After = 1 };
struct stDate
{
	short Year=0, Month=0, Day=0;
};
struct stPeriod
{
	stDate DateStart;
	stDate DateEnd;
};
stDate ReadDate()
{
	stDate Date;
	Date.Day = InputLib::ReadNumber("a Day");
	Date.Month = InputLib::ReadNumber("a Month");
	Date.Year = InputLib::ReadNumber("a Year");
	return Date;
}
stPeriod ReadPeriod()
{
	stPeriod DatePeriod;
	cout << "\nEnter Start Date:\n\n";
	DatePeriod.DateStart = ReadDate();
	cout << "\nEnter End Date: \n\n";
	DatePeriod.DateEnd = ReadDate();
	return DatePeriod;
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
int DaysInMonth(stDate Date)
{
	return DaysInMonth(Date.Year, Date.Month);
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
bool IsDate1BeforeDate2(stDate Date1,stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
			Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
int CountPeriodLength(stPeriod Period)
{
	int counter = 0;
	while (IsDate1BeforeDate2(Period.DateStart, Period.DateEnd))
	{
		Period.DateStart = IncreaseDateByOneDay(Period.DateStart);
		counter++;
	}
	return counter;
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriod Period = ReadPeriod();
	cout << "Period Length is: " << CountPeriodLength(Period);
	return 0;
}
