#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

struct stCountString
{
	int CapitalCounter = 0, SmallCounter = 0, stringLength = 0;
};

stCountString CountStringInfo(string& text)
{
	stCountString CountString;
	for (char& character : text)
	{
		if (character != ' ')
			{
				if (character < 123 && character > 96)
				{
					CountString.SmallCounter++;
				}
				else if (character < 91 && character > 64)
				{
					CountString.CapitalCounter++;
				}
			}
	}
	CountString.stringLength = text.length();
	return CountString;
}

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	stCountString CountString = CountStringInfo(text);
	cout << "Text String Length = " << CountString.stringLength << endl;
	cout << "Text Capital Counter = " << CountString.CapitalCounter << endl;
	cout << "Text Small Counter = " << CountString.SmallCounter << endl;
	return 0;
}