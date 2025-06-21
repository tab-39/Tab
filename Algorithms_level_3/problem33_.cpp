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

int CountVowel(string text)
{
	int counter = 0;
	for (char& letter : text)
	{
		if (IsVowel(letter))
		{
			counter ++;
		}
	}
	return counter;
}

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	int countVowel = CountVowel(text);
	cout << "Counter Vowel = " << countVowel << endl;
	return 0;
}
