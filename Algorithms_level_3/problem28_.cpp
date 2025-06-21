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
	string text = InputLib::ReadText("Please, enter you text: ");
	cout << "text before editing: \n" << text;
	MyLib::ChangeStringCase(text);
	cout << "\ntext after editing: \n" << text;
	return 0;
}
