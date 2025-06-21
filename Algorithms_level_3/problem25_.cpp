#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void titleLower(string& text)
{
	bool isFirstLetter = true;
	for (char & letter : text)
	{
		if (letter != ' ' && isFirstLetter)
		{
			if (letter < 91 && letter > 64)
			{
				letter += 32;
			}
		}
		isFirstLetter = (letter == ' ')? true : false;
	}
}



int main()
{
	string text = InputLib::ReadText("Please, enter your string: ");
	cout << "Text Before TitleLower: \n" << text << endl;
	titleLower(text);
	cout << "Text After TitleLower: \n" << text << endl;
	return 0;
}
