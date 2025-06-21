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
bool IsPeriodOverLap(stPeriod FirstPeriod, stPeriod SecondPeriod)
{
	return !((DateCompare(FirstPeriod.DateStart, SecondPeriod.DateEnd) == After) || (DateCompare(FirstPeriod.DateEnd, SecondPeriod.DateStart) == Before));
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriod FirstPeriod = ReadPeriod();
	cout << "\nEnter Period2:\n";
	stPeriod SecondPeriod = ReadPeriod();
	if (IsPeriodOverLap(FirstPeriod, SecondPeriod))
		cout << "Yes it is overlap.\n";
	else
		cout << "No it is't overlapping.\n";
	return 0;
}
