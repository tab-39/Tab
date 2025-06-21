#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"


string TrimLeft(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ')
        {
            return text.substr(i, text.length()-1);
        }
	}
	return "";
}

string TrimRight(string text)
{
	for (int i = text.length(); i > 0; i--)
	{
		if (text[i] != ' ')
        {
            return text.substr(0, i+1);
        }
	}
	return "";
}

string Trim(string text)
{
	return TrimRight(TrimLeft(text));
}

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	cout << "Trim Left:" << TrimLeft(text);
	cout << "\nTrim Right: " << TrimRight(text);
	cout << "\nTrim: " << Trim(text);
	
	return 0;
}
