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
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month --;
			Date.Day = DaysInMonth(Date.Year, Date.Month);
		}
	}
	else
		Date.Day--;
	return Date;
}
stDate DecreaseDateByXDays(stDate Date, int counter)
{
	
	for (int i = 1; i <= counter; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
stDate DecreaseDateByXWeeks(stDate Date, int counter)
{
	for (int i = 1; i <= counter; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}
stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
		Date.Month--;
	short DaysInM = DaysInMonth(Date.Year, Date.Month);
	if (Date.Day > DaysInM)
	{
		Date.Day = DaysInM;
	}
	
	return Date;
}
stDate DecreaseDateByXMonth(stDate Date, int counter)
{
	for (int i = 1; i <= counter; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}
stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}
stDate DecreaseDateByXYear(stDate Date, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
stDate DecreaseDateByXYearF(stDate Date, int counter)
{
	Date.Year -= counter;
	return Date;
}
stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}
stDate DecreaseDateByXDecade(stDate Date, int counter)
{
	for (int i = 1; i <= counter; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}
stDate DecreaseDateByXDecadeF(stDate Date, int counter)
{
	Date.Year -= (10*counter);
	return Date;
}
stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}
stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}
int main()
{
	stDate Date = ReadDate();
	cout << "Date After:\n";
	Date = IncreaseDateByOneDay(Date);
	cout << "01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDays(Date, 10);
	cout << "02-Subtracting 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Subtracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXWeeks(Date, 10);
	cout << "04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneMonth(Date);
	cout << "05-Subtracting One Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXMonth(Date, 5);
	cout << "06-Subtracting 5 Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneYear(Date);
	cout << "07-Subtracting One Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXYear(Date, 10);
	cout << "08-Subtracting 10 Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXYearF(Date, 10);
	cout << "09-Subtracting 10 Year Faster is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneDecade(Date);
	cout << "10-Subtracting one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDecade(Date, 10);
	cout << "11-Subtracting 10 Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDecadeF(Date, 10);
	cout << "12-Subtracting 10 Decade Faster is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneCentury(Date);
	cout << "13-Subtracting One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneMillennium(Date);
	cout << "14-Subtracting One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	return 0;
}
