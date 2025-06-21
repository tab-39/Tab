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
string ReadDateAsString()
{
	string Date;
	Date = InputLib::ReadText("Please Enter Date dd/mm/yyyy: ");
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
int DaysInMonth(stDate Date)
{
	return DaysInMonth(Date.Year, Date.Month);
}
bool ValidateDate(stDate Date)
{
	return (Date.Day <= DaysInMonth(Date) && Date.Day > 0) && (Date.Month <= 12 && Date.Month > 0) && (Date.Year > 0);
}
stDate StringToDate(string SDate)
{
	stDate Date;
	vector <string> DateV;
	DateV = MyLib::Split(SDate, "/");
	Date.Day = stoi(DateV[0]);
	Date.Month = stoi(DateV[1]);
	Date.Year = stoi(DateV[2]);
	return Date;
}
string DateToString(stDate DString)
{
	return to_string(DString.Day) + '/' + to_string(DString.Month) + "/" + to_string(DString.Year);
}

int main()
{
	string Date = ReadDateAsString();
	stDate DateC = StringToDate(Date);
	cout << "Day:" << DateC.Day << endl;
	cout << "Month:" << DateC.Month << endl;
	cout << "Year:" << DateC.Year << endl;
	string DateStringC = DateToString(DateC);
	cout << "You Entered: " << DateStringC << endl;

	return 0;
}
