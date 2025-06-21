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
string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = S1.find(StringToReplace);
	}
	return S1;
}
string FormateDate(stDate date, string DateFormat = "dd/mm/yyyy")
{
	string FormateDateString = "";
	FormateDateString = ReplaceWordInString(DateFormat, "dd", to_string(date.Day));
	FormateDateString = ReplaceWordInString(FormateDateString, "mm", to_string(date.Month));
	FormateDateString = ReplaceWordInString(FormateDateString, "yyyy", to_string(date.Year));
	return FormateDateString;
}

int main()
{
	string DateS = ReadDateAsString();
	stDate Date = StringToDate(DateS);

	cout << FormateDate(Date) << endl;
	cout << FormateDate(Date, "yyyy/dd/mm") << endl;
	cout << FormateDate(Date, "mm/dd/yyyy") << endl;
	cout << FormateDate(Date, "mm-dd-yyyy") << endl;
	cout << FormateDate(Date, "dd-mm-yyyy") << endl;
	cout << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << endl;


	return 0;
}
