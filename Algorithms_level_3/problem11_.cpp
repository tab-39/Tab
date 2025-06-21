#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void FillMatrixWithRandomNumber(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			arr[i][j] = MathLib::RandomNumber(1, 10);
		}
		
	}
}

void Print3by3Matrix(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			printf("%0*d   ", 2, arr[i][j]);
		}	
		cout << endl;
	}
}

int SumMatrix(int arr[3][3], int First, int Second)
{
	int SumOfMatrix = 0; 
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			SumOfMatrix += arr[i][j];
		}
	}
	return SumOfMatrix;
}

bool CheckMatrixEqual(int arr[3][3], int arr2[3][3], int First, int Second)
{
	return SumMatrix(arr, First, Second) == SumMatrix(arr2, First, Second);
}

int main()
{
	srand(unsigned(time(NULL)));
	int arr[3][3], arr2[3][3];
	FillMatrixWithRandomNumber(arr, 3, 3);
	Print3by3Matrix(arr, 3, 3);
	cout << "Second Matrix: " << endl;
	FillMatrixWithRandomNumber(arr2, 3, 3);
	Print3by3Matrix(arr2, 3, 3);
	if (CheckMatrixEqual(arr, arr2, 3, 3))
		cout << "Yes: equal" << endl;
	else
		cout << "No: equal" << endl;

	return 0;
}
