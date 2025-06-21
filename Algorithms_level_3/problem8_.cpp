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

void Multiply2Matrix(int arr1[3][3], int arr2[3][3], int arr3[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			arr1[i][j] = arr2[i][j]  * arr3[i][j] ;
		}
		
	}
}

void Print3by3Matrix(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			cout << setw(4) << arr[i][j];

		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	int arr2[3][3];
	int arrMulti[3][3];
	FillMatrixWithOrderNumber(arr, 3, 3);
	cout << "The following is a 3x3 ordered matrix: \n";
	Print3by3Matrix(arr, 3, 3);
	FillMatrixWithOrderNumber(arr2, 3, 3);
	cout << "The following is a 3x3 ordered matrix 2: \n";
	Print3by3Matrix(arr2, 3, 3);

	Multiply2Matrix(arrMulti, arr2, arr, 3, 3);

	cout << "The following is a 3x3 ordered matrix Multiple: \n";
	Print3by3Matrix(arrMulti, 3, 3);
	return 0;
}
