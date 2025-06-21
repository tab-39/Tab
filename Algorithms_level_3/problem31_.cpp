#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

int CountLetter(string& text, char count, bool MatchCase=true)
{
	int counter = 0;
	for (char & character : text)
	{
		if (MatchCase)
		{
			if (character == count)
			{
				counter++;
			}
		}
		else
			if (tolower(character) == tolower(count))
			{
				counter++;
			}
		
	}
	return counter;
}

int main()
{
	string text = InputLib::ReadText("Please, enter your text: ");
	char character = InputLib::ReadChar();
	cout << "Letter " << character << " counter is " << CountLetter(text, character);
	cout << "\nLetter " << character << " or " << MyLib::ChangeCase(character) << " counter is " << CountLetter(text, character, false);
	return 0;
}
