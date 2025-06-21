#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void title(string& text)
{
	bool isFirstLetter = true;
	for (char & letter : text)
	{
		if (letter != ' ' && isFirstLetter)
		{
			if (letter < 123 && letter > 96)
			{
				letter -= 32;
			}
		}
		isFirstLetter = (letter == ' ')? true : false;
	}
}



int main()
{
	string text = InputLib::ReadText("Please, enter your string: ");
	cout << "Text Before Title: \n" << text << endl;
	title(text);
	cout << "Text After Title: \n" << text << endl;
	return 0;
}
