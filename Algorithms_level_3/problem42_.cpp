#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

string ReplaceWordInString(string text, string StringToReplace, string ReplaceTo)
{
	short pos = text.find(StringToReplace);
	while (pos != std::string::npos)
	{
		text = text.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = text.find(StringToReplace);
	}
	return text;
}

int main()
{
	string s1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "KSA";

	cout << "\nOriginal String\n" << s1;
	cout << "\n\nString After Replace: ";
	cout << "\n" << ReplaceWordInString(s1, StringToReplace, ReplaceTo);
	return 0;
}
