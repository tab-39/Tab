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

bool CheckMatrixIdentity(int arr[3][3], int First, int Second)
{
	short scar = arr[0][0];
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second; j++)
		{
			if (i == j && arr[i][j] != scar)
			{
				return false;
			}
			else if (i != j && arr[i][j] != 0)
			{
				return false;
			}
			
		}	
	}
	return true;
}

int main()
{
	srand(unsigned(time(NULL)));
	int arr[3][3] = { {4, 0, 0}, {0, 4, 0}, {0, 0, 4} };
	Print3by3Matrix(arr, 3, 3);
	if (CheckMatrixIdentity(arr, 3, 3))
	{
		cout << "Yes";
	}
	else
		cout << "No";
	

	return 0;
}
