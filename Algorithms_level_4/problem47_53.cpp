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
bool IsLeapYear(int YearNumber)
{
	return YearNumber % 400 == 0 || (YearNumber % 4 == 0 && YearNumber % 100 != 0);
}
bool IsEndOfWeek(short DayOrder)
{
	return (DayOrder == 6);
}
bool IsWeekEnd(short DayOrder)
{
	return (DayOrder == 5 || DayOrder == 6);
}
bool IsBusinessDay(short DayOrder)
{
	return !IsWeekEnd(DayOrder);
}
short DaysUntilTheEndOfWeek(stDate Date)
{
	return  6 - DayOrder(Date);
}
short DaysUntilTheEndOfMonth(stDate Date)
{
	short DayMonth = DaysInMonth(Date);
	return DayMonth - Date.Day;
}
short DaysUntilTheEndOfYear(stDate Date)
{
	int Counter = 0;
	for (int i = Date.Month+1; i < 13; i++)
	{
		Counter += DaysInMonth(Date.Year, i);
	}
	Counter += DaysInMonth(Date) - Date.Day;
	return Counter;
}

int main()
{
	stDate Date = ReadDate();
	short DOrder = DayOrder(Date);
	cout << "Today is " << DayNameByOrder(DOrder) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	cout << "Is it End of Week?\n\n";
	if (IsEndOfWeek(DOrder))
		cout << "Yes, it is a end of week\n\n";
	else
		cout << "No, Not end of week\n\n";
	
	cout << "Is it Weekend?\n";
	if (IsWeekEnd(DOrder))
		cout << "Yes, it is a week end\n\n";
	else
		cout << "No, Today is " << DayNameByOrder(DOrder) << " Not week end\n\n";
	
	cout << "Is it Business day?\n";
	if (IsBusinessDay(DOrder))
		cout << "Yes, it is Business day\n\n";
	else
		cout << "No, Not Business day\n\n";
	
	cout << "Days until end of Week: " << DaysUntilTheEndOfWeek(Date) << "Day(s).\n";
	cout << "Days until end of Month: " << DaysUntilTheEndOfMonth(Date) << "Day(s).\n";
	cout << "Days until end of Year: " << DaysUntilTheEndOfYear(Date) << "Day(s).\n";
	return 0;
}
