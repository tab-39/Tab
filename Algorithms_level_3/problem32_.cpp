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

int main()
{
	char character = InputLib::ReadChar();
	if (IsVowel(character))
	{
		cout << "Yes Letter '" << character << "' is vowel\n";
	}
	else
		cout << "No Letter '" << character << "' is not vowel\n";

	return 0;
}
