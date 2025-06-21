#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void FirstLetterInString(string text)
{
	bool isFirstLetter = true;
	for (char letter : text)
	{
		if (letter != ' ' && isFirstLetter)
		{
			cout << letter << endl;
		}
		isFirstLetter = (letter == ' ')? true : false;
	}
}



int main()
{
	string text = InputLib::ReadText("Please, enter your string: ");
	FirstLetterInString(text);
	return 0;
}
