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
	int counter = 0;
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			counter ++;
			arr[i][j] = counter;
		}
		
	}
}

void FillMatrixWithTransposedNumber(int arr2[3][3], int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			arr2[i][j] = arr[j][i];
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
	int arr[3][3];
	int Tarr[3][3];
	FillMatrixWithOrderNumber(arr, 3, 3);
	cout << "The following is a 3x3 ordered matrix: \n";
	Print3by3Matrix(arr, 3, 3);
	FillMatrixWithTransposedNumber(Tarr, arr, 3, 3);
	cout << "The following is the Transposed matrix: \n";
	Print3by3Matrix(Tarr, 3, 3);
	return 0;
}
