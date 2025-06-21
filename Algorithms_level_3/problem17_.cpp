#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void Print3by3Matrix(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			cout << arr[i][j] << "  ";
		}	
		cout << endl;
	}
}

bool IsInMatrix(int arr[3][3],int NumberToFind, int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			if (arr[i][j] == NumberToFind)
			{
				return true;
			}
			
		}	
	}
	return false;
}

int main()
{
	srand(unsigned(time(NULL)));
	int arr[3][3] = { {3, 2, 0}, {0, 4, 3}, {0, 0, 4} };
	Print3by3Matrix(arr, 3, 3);
	int NumberToFound = InputLib::ReadNumber("Number To Search In Matrix");
	if (IsInMatrix(arr,NumberToFound, 3, 3))
		cout << "Yes: It Is There" << endl;
	else
		cout << "No: It's NOT There" << endl;

	return 0;
}
