#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"


int CountWords(string text)
{
	int counter = 0;
	string delim = " ";
	short pos = 0;
	string sWord = "";

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			counter++;
		}
		text.erase(0, pos+delim.length());
	}
	if (text != "")
	{
		counter++;
	}
	return counter;
}

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	cout << "The number of words in your string is : " << CountWords(text);
	
	return 0;
}
