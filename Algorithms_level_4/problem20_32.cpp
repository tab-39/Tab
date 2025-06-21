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
stDate IncreaseDateByXDays(stDate Date, int counter)
{
	for (int i = 1; i <= counter; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
stDate IncreaseDateByXWeeks(stDate Date, int counter)
{
	for (int i = 1; i <= counter; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}
stDate IncreaseDateByOneMonth(stDate Date)
{
	int DaysMonth = DaysInMonth(Date.Year, Date.Month);
	Date = IncreaseDateByXDays(Date, DaysMonth);
	return Date;
}
stDate IncreaseDateByXMonth(stDate Date, int counter)
{
	for (int i = 1; i <= counter; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}
stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}
stDate IncreaseDateByXYear(stDate Date, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}
stDate IncreaseDateByXYearF(stDate Date, int counter)
{
	Date.Year += counter;
	return Date;
}
stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}
stDate IncreaseDateByXDecade(stDate Date, int counter)
{
	for (int i = 1; i <= counter; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}
stDate IncreaseDateByXDecadeF(stDate Date, int counter)
{
	Date.Year += (10*counter);
	return Date;
}
stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}
int main()
{
	stDate Date = ReadDate();
	cout << "Date After:\n";
	Date = DecreaseDateByOneDay(Date);
	cout << "01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXDays(Date, 10);
	cout << "02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneWeek(Date);
	cout << "03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXWeeks(Date, 10);
	cout << "04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneMonth(Date);
	cout << "05-Adding One Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXMonth(Date, 5);
	cout << "06-Adding 5 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneYear(Date);
	cout << "07-Adding One Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXYear(Date, 10);
	cout << "08-Adding 10 Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXYearF(Date, 10);
	cout << "09-Adding 10 Year Faster is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneDecade(Date);
	cout << "10-Adding one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXDecade(Date, 10);
	cout << "11-Adding 10 Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXDecadeF(Date, 10);
	cout << "12-Adding 10 Decade Faster is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneCentury(Date);
	cout << "13-Adding One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneMillennium(Date);
	cout << "14-Adding One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	return 0;
}
