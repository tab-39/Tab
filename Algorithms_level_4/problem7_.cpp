#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

int DayOrder(int Year, int Month, int Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12*a - 2;
	return (Day + y + (y/4) - (y/100) + (y/400) + (31*m / 12)) % 7;
} 
string DayNameByOrder(int DayOrder)
{
	string DaysName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	return DaysName[DayOrder];
}

int main()
{
	int Year = InputLib::ReadNumber("a Year");
	int Month = InputLib::ReadNumber("a Month");
	int Day = InputLib::ReadNumber("a Day");
	int DayOrderIndex = DayOrder(Year, Month, Day);
	cout << "Date     :" << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order:" << DayOrderIndex+1 << endl;
	cout << "Day Name :" << DayNameByOrder(DayOrderIndex) << endl;
	return 0;
}
