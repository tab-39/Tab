#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

string RemoveAllPunctuations(string text)
{
	string RemovedPunctuations = "";
	for (char& character : text)
	{
		if (!ispunct(character))
		{
			RemovedPunctuations += character;
		}
		
	}
	return RemovedPunctuations;
}

int main()
{
	string text = InputLib::ReadText("Please, enter your string: ");
	cout << "Original : \n" << text;
	cout << "Punctuations Removed: \n" << RemoveAllPunctuations(text);
	return 0;
}
