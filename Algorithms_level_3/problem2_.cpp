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

void FillMatrixWithRandomNumber(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			arr[i][j] = MathLib::RandomNumber(1, 100);
		}
		
	}
}

void Print3by3Matrix(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			cout << setw(5) << arr[i][j];

		}
		cout << endl;
	}
}

void SumRowInMatrix(int arr[3][3], int First, int Second)
{

	for (int i = 0; i < First; i++)
	{
		int sumOfRow = 0;
		for (int j = 0; j < Second; j++)
		{
			sumOfRow += arr[i][j];

		}
		cout << "Row " << i+1 <<  " Sum = " << sumOfRow << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Matrix3by3[3][3];

	FillMatrixWithRandomNumber(Matrix3by3, 3, 3);
	Print3by3Matrix(Matrix3by3, 3, 3);
	SumRowInMatrix(Matrix3by3, 3, 3);
	return 0;
}
