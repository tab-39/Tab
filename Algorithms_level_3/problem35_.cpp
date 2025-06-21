#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"


void PrintWords(string text)
{
	string delim = " ";
	cout << "\nYour string words are: \n\n";
	short pos = 0;
	string sWord = "";

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			cout << sWord << endl;
		}
		text.erase(0, pos+delim.length());
	}
	if (text != "")
	{
		cout << text << endl;
	}
	
}

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	PrintWords(text);
	
	return 0;
}
