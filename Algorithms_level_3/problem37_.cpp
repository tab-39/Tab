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

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	vector <string> vText;
	vText = Split(text, "-");
	
	cout << "\nTokens: " << vText.size() << endl;

	for (string& word : vText)
	{
		cout << word << endl;
	}
	return 0;
}
