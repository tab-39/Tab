#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

bool IsVowel(char character)
{
	return (tolower(character) == 'a' || tolower(character) == 'e' || tolower(character) == 'i' || tolower(character) == 'o' || tolower(character) == 'u');
}

void PrintVowel(string text)
{
	for (char& letter : text)
	{
		if (IsVowel(letter))
			cout << letter << "   ";
	}
}

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	PrintVowel(text);
	
	return 0;
}
