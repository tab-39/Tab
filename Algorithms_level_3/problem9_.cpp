#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void FillMatrixWithOrderNumber(int arr[3][3], int First, int Second)
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

void PrintRowMatrix(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		printf("%0*d   ", 2, arr[Second/2][i]);
	}
	cout << endl;
}

void PrintColMatrix(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		printf("%0*d   ", 2, arr[i][Second/2]);
	}
	cout << endl;
}

int main()
{
	int arr[3][3];
	FillMatrixWithOrderNumber(arr, 3, 3);
	cout << "The following is a 3x3 ordered matrix: \n";
	Print3by3Matrix(arr, 3, 3);
	cout << "Middle Row Matrix: \n";
	PrintRowMatrix(arr, 3, 3);
	cout << "Middle Col Matrix: \n";
	PrintColMatrix(arr, 3, 3);
	return 0;
}
