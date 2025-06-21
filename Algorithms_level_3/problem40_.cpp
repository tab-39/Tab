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
	
	return text.substr(0, text.length() - delim.length());
}

string JoinString(string arr[100], int length, string delim)
{
	string text = "";
	for (int i = 0; i < length; i++)
	{
		text += arr[i] + delim;
	}
	
	return text.substr(0, text.length() - delim.length() - delim.length());
}

int main()
{
	vector <string> vNames = {"Turki", "barayan", "Zeed", "Hsnon", "Demma", "barayan"};
	string arr[7] = {"Turki", "barayan", "Zeed", "Hsnon", "Demma", "barayan"};

	cout << "Vector after Join: \n" << JoinString(vNames, ", , ");
	cout << "\narr after Join: \n" << JoinString(arr, 7, ", , ");
	return 0;
}
