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
	int TotalDays=0, AddedDays=0, SubtractDays=0;
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

stDate DateByDays(stDate Date)
{
	stDate NewDate;
	Date.TotalDays += Date.AddedDays;

	int DaysRemaining = Date.TotalDays;
	short MonthDays = 0;
	NewDate.Year = Date.Year;
	NewDate.Month = 1;

	while (true)
	{
		MonthDays = DaysInMonth(NewDate.Year, NewDate.Month);
		if (DaysRemaining > MonthDays)
		{
			DaysRemaining -= MonthDays;
			NewDate.Month++;
			if (NewDate.Month > 12)
			{
				NewDate.Year++;
				NewDate.Month = 1;
			}
		}
		else
		{
			NewDate.Day = DaysRemaining;
			break;
		}
	}
	return NewDate;
}

int main()
{
	stDate Date;
	stDate AddDate;
	Date.Day = InputLib::ReadNumber("a Day");
	Date.Month = InputLib::ReadNumber("a Month");
	Date.Year = InputLib::ReadNumber("a Year");
	Date.AddedDays = InputLib::ReadNumber("Days to add");
	Date.TotalDays = CountingDays(Date);
	AddDate = DateByDays(Date);
	cout << "Date after adding[" << Date.AddedDays << "]: ";
	cout << AddDate.Day << "/" << AddDate.Month << "/" << AddDate.Year << endl;
	return 0;
}
