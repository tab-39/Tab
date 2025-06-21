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
	short Year=0, Month=0, Day=0, TotalDays=0;
};

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

int CountingDays(stDate Date)
{
	int Counter = 0;
	for (int i = 1; i < Date.Month; i++)
	{
		Counter += DaysInMonth(Date.Year, i);
	}
	Counter += Date.Day;
	return Counter;
}

stDate DateByDays(int Days, int Year)
{
	stDate Date;
	Date.TotalDays = Days;
	short DaysRemaining = Days;
	short MonthDays = 0;
	Date.Year = Year;
	Date.Month = 1;
	while (true)
	{
		MonthDays = DaysInMonth(Year, Date.Month);
		if (DaysRemaining > MonthDays)
		{
			DaysRemaining -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = DaysRemaining;
			break;
		}
	}
	return Date;
}

int main()
{
	stDate Date;
	Date.Day = InputLib::ReadNumber("a Day");
	Date.Month = InputLib::ReadNumber("a Month");
	Date.Year = InputLib::ReadNumber("a Year");
	Date.TotalDays = CountingDays(Date);
	cout << "Number of Days from the beginning of the year is: " << Date.TotalDays << endl;
	
	Date = DateByDays(Date.TotalDays, Date.Year);
	cout << "Date for [" << Date.TotalDays << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	return 0;
}
