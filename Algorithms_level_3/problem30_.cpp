#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

int CountLetter(string& text, char count)
{
	int counter;
	for (char & character : text)
	{
		if (character == count)
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
	return 0;
}