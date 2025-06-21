#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

vector<string> Split(string text, string delim = " ")
{
	vector <string> vText;
	int counter = 0;
	short pos = 0;
	string sWord = "";

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			vText.push_back(sWord);
		}
		text.erase(0, pos+delim.length());
	}
	if (text != "")
	{
		vText.push_back(text);
	}
	return vText;
}

string JoinString(vector <string> &vString, string delim)
{
	string text = "";
	for (string&  word: vString)
	{
		text += word + delim;
	}
	
	return text.substr(0, text.length()-delim.length());
}

string Lower(string text)
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
	return text;
}

string ReplaceWordInString(string text, string StringToReplace, string ReplaceTo, bool MatchCase=true)
{
	vector <string> vText = Split(text, " ");
	for (string& word : vText)
	{
		if (MatchCase)
		{
			if (word == StringToReplace)
			{
				word = ReplaceTo;
			}
		}
		else
		{
			if (Lower(word) == Lower(StringToReplace))
			{
				word = ReplaceTo;
			}
		}
	}

	return JoinString(vText, " ");
}

int main()
{
	string s1 = "Welcome to Jordan , jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "KSA";

	cout << "\nOriginal String\n" << s1;
	cout << "\n\nString After Replace matchCase: ";
	cout << "\n" << ReplaceWordInString(s1, StringToReplace, ReplaceTo);
	cout << "\n\nString After Replace Not matchCase: ";
	cout << "\n" << ReplaceWordInString(s1, StringToReplace, ReplaceTo, false);
	return 0;
}
