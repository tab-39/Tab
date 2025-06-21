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
short ReadVacationDay()
{
	short Days;
	cout << "Please enter vacation days: ", cin >> Days;
	return Days;
}
int DayOrder(stDate Date)
{
	int a = (14 - Date.Month) / 12;
	int y = Date.Year - a;
	int m = Date.Month + 12*a - 2;
	return (Date.Day + y + (y/4) - (y/100) + (y/400) + (31*m / 12)) % 7;
} 
string DayNameByOrder(int DayOrder)
{
	string DaysName[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	return DaysName[DayOrder];
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
bool IsDate1BeforeDate2(stDate Date1,stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
			Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsWeekEnd(short DayOrder)
{
	return (DayOrder == 5 || DayOrder == 6);
}
bool IsBusinessDay(short DayOrder)
{
	return !IsWeekEnd(DayOrder);
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
stDate VacationEndsByVDay(stDate VacationS, short VacationDays)
{
	short WeekEndCounter = 0;
	while (IsWeekEnd(DayOrder(VacationS)))
	{
		VacationS = IncreaseDateByOneDay(VacationS);
	}
	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{
		if (IsWeekEnd(DayOrder(VacationS)))
			WeekEndCounter++;
		VacationS = IncreaseDateByOneDay(VacationS);
	}
	while (IsWeekEnd(DayOrder(VacationS)))
	{
		VacationS = IncreaseDateByOneDay(VacationS);
	}
	return VacationS;
}

int main()
{
	cout << "Vacation Starts: \n";
	stDate VacationS = ReadDate();
	short VacationDays = ReadVacationDay();
	stDate VacationEnd = VacationEndsByVDay(VacationS, VacationDays);
	cout << "Return Date: " << DayNameByOrder(DayOrder(VacationEnd)) << " , " << VacationEnd.Day << "/" << VacationEnd.Month << "/" << VacationEnd.Year << endl; 
	return 0;
}
