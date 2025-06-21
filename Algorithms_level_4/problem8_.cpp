#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

bool IsLeapYear(int YearNumber)
{
	return YearNumber % 400 == 0 || (YearNumber % 4 == 0 && YearNumber % 100 != 0);
}

int DayOrder(int Year, int Month, int Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12*a - 2;
	return (Day + y + (y/4) - (y/100) + (y/400) + (31*m / 12)) % 7;
} 

string MonthNameByOrder(int MonthOrder)
{
	string MonthsName[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	return MonthsName[MonthOrder-1];
}

int DaysInMonth(int Year, int Month)
{
	if (Month < 1 || Month > 12)
		return 0;
	short arr31Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return (Month == 2 && IsLeapYear(Year))? 29 : arr31Days[Month-1];
}

void PrintMonthCalender(int Year, int Month)
{
	int DayNumber = DayOrder(Year, Month, 1);
	cout << "  _______________" << MonthNameByOrder(Month) << "_______________\n\n";
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n";
	int i;
	for (i = 0; i < DayNumber; i++)
	{
		cout << "     ";
	}
	for (int j = 1; j <= DaysInMonth(Year, Month); j++)
	{
		cout << setw(5) << j;
		if (++i == 7)
		{
			i = 0;
			cout << endl;
		}
	}
	cout << "\n  _________________________________";
}

int main()
{
	int Year = InputLib::ReadNumber("a Year");
	int Month = InputLib::ReadNumber("a Month");
	PrintMonthCalender(Year, Month);
	return 0;
}
