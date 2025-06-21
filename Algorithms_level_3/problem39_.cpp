#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

string JoinString(vector <string> &vString, string delim)
{
	string text = "";
	for (string&  word: vString)
	{
		text += word + delim;
	}
	
	return text.substr(0, text.length()-delim.length());
}

int main()
{
	vector <string> vNames = {"Turki", "barayan", "Zeed", "Hsnon", "Demma", "barayan"};
	cout << "Vector after Join: \n" << JoinString(vNames, ", ");
	return 0;
}