#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"


int main()
{
	char character = InputLib::ReadChar();
	cout << "char before editing: \n" << character;
	MyLib::ChangeCase(character);
	cout << "\nchar after editing: \n" << character;
	return 0;
}
