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

bool IsPalindromeMatrix(int arr[3][3], int First, int Second)
{
	for (int i = 0; i < First; i++)
	{
		for (int j = 0; j < Second / 2; j++)
		{
			if (arr[i][j] != arr[i][First-1-j])
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
	int arr[3][3] = { {3, 2, 3}, {9, 4, 9}, {6, 2, 6} };
	Print3by3Matrix(arr, 3, 3);
	if(IsPalindromeMatrix(arr, 3, 3))
		cout << "Yes: it's palindrome matrix.\n";
	else
		cout << "No: it's NOT palindrome matrix.\n";
	

	return 0;
}
