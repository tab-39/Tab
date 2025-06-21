#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void Upper(string& text)
{
	for (char & letter : text)
	{
		if (letter != ' ')
		{
			if (letter < 123 && letter > 96)
			{
				letter -= 32;
			}
		}
	}
}

void Lower(string& text)
{
	for (char & letter : text)
	{
		if (letter != ' ')
		{
			if (letter < 91 && letter > 64)
			{
				letter += 32;
			}
		}
	}
}


int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	cout << "text before editing: \n" << text;
	Upper(text);
	cout << "\ntext Upper editing: \n" << text;
	Lower(text);
	cout << "\ntext Lower editing: \n" << text;
	return 0;
}