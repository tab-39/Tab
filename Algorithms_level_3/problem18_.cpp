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

void PrintIntersectedNumbers(int arr[3][3],int arr2[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			if (IsInMatrix(arr2, arr[i][j], First, Second))
			{
				cout << arr[i][j] << endl;
			}
			
		}	
	}
}

int main()
{
	srand(unsigned(time(NULL)));
	int arr[3][3] = { {3, 2, 0}, {0, 4, 3}, {0, 0, 4} };
	int arr2[3][3] = { {8, 3, 5}, {6, 4, 3}, {3, 45, 4} };
	Print3by3Matrix(arr, 3, 3);
	Print3by3Matrix(arr2, 3, 3);
	PrintIntersectedNumbers(arr, arr2, 3, 3);

	return 0;
}
