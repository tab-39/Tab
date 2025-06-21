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

int MinMatrix(int arr[3][3], int First, int Second)
{
	int MinNumber = arr[0][0];
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			
			if (MinNumber > arr[i][j])
			{
				MinNumber = arr[i][j];
			}
			
		}	
	}
	return MinNumber;
}

int MaxMatrix(int arr[3][3], int First, int Second)
{
	int MaxNumber = arr[0][0];
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			if (MaxNumber < arr[i][j])
			{
				MaxNumber = arr[i][j];
			}
			
		}	
	}
	return MaxNumber;
}

int main()
{
	srand(unsigned(time(NULL)));
	int arr[3][3] = { {3, 2, 0}, {0, 4, 3}, {0, 0, 4} };
	Print3by3Matrix(arr, 3, 3);
	int MaxNumber = MaxMatrix(arr, 3, 3);
	int MinNumber = MinMatrix(arr, 3, 3);

	cout << "Min Number is:\n" << MinNumber << endl;
	cout << "Max Number is:\n" << MaxNumber << endl;
	

	return 0;
}
