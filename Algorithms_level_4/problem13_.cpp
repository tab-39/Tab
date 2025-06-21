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

bool IsDate1BeforeDate2(stDate Date1,stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
			Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
	stDate Date1 = ReadDate();
	stDate Date2 = ReadDate();
	if (IsDate1BeforeDate2(Date1, Date2))
		cout << "\nYes, Date1 is Less than Date2.";
	else
		cout << "\nNo, Date1 is Not Less than Date2.";
	return 0;
}
