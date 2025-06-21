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
bool IsDate1EqualDate2(stDate Date1,stDate Date2)
{
	return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day? true : false) : false) : false;
}
bool IsDate1AfterDate2(stDate Date1,stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1,Date2) && !IsDate1EqualDate2(Date1,Date2));
}
enDateCompare DateCompare(stDate Date1,stDate Date2)
{
	if (IsDate1BeforeDate2(Date1,Date2))
		return enDateCompare::Before;
	else if (IsDate1EqualDate2(Date1,Date2))
		return enDateCompare::Equal;
	return enDateCompare::After;
}
bool IsDateWithinPeriod(stPeriod Period, stDate DateCheck)
{
	return (DateCompare(Period.DateStart, DateCheck) == Before) && (DateCompare(Period.DateEnd, DateCheck) == After); 
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
bool IsPeriodOverLap(stPeriod FirstPeriod, stPeriod SecondPeriod)
{
	return !((DateCompare(FirstPeriod.DateStart, SecondPeriod.DateEnd) == After) || (DateCompare(FirstPeriod.DateEnd, SecondPeriod.DateStart) == Before));
}
int DaysOverLap(stPeriod FirstPeriod, stPeriod SecondPeriod)
{
	int Period1Length = CountPeriodLength(FirstPeriod);
	int Period2Length = CountPeriodLength(SecondPeriod);
	Period1Length++;
	Period2Length++;
	int OverlapDays = 0;
	if (!IsPeriodOverLap(FirstPeriod, SecondPeriod))
		return 0;
	if (Period1Length < Period2Length)
	{
		while (DateCompare(FirstPeriod.DateStart, FirstPeriod.DateEnd) == Before)
		{
			if (IsDateWithinPeriod(SecondPeriod, FirstPeriod.DateStart))
				OverlapDays++;
			FirstPeriod.DateStart = IncreaseDateByOneDay(FirstPeriod.DateStart);
		}
	}
	else
	{
		while (DateCompare(SecondPeriod.DateStart, SecondPeriod.DateEnd) == Before)
		{
			if (IsDateWithinPeriod(FirstPeriod, SecondPeriod.DateStart))
				OverlapDays++;
			SecondPeriod.DateStart = IncreaseDateByOneDay(SecondPeriod.DateStart);
		}
		
	}
	return OverlapDays;

}

int main()
{
	cout << "Enter Period1:\n";
	stPeriod FirstPeriod = ReadPeriod();
	cout << "\nEnter Period2:\n";
	stPeriod SecondPeriod = ReadPeriod();

	cout << "Overlap Days Count Is: " << DaysOverLap(FirstPeriod, SecondPeriod);

	return 0;
}
