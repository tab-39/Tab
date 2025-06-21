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

int CountNumberInMatrix(int arr[3][3], int NCounter, int First, int Second)
{
	short counter = 0;
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			if (arr[i][j] == NCounter)
			{
				counter++;
			}
			
		}	
	}
	return counter;
}

bool IsSparseMatrix(int arr[3][3], int First, int Second)
{
	int HMatrixSize = First*Second / 2;
	return CountNumberInMatrix(arr, 0, First, Second) > HMatrixSize;
}

int main()
{
	srand(unsigned(time(NULL)));
	int arr[3][3] = { {3, 2, 0}, {0, 4, 3}, {0, 0, 4} };
	Print3by3Matrix(arr, 3, 3);

	if (IsSparseMatrix(arr, 3, 3))
		cout << "Yes: It is Sparse" << endl;
	else
		cout << "No: It's NOT Sparse" << endl;

	return 0;
}
