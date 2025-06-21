#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void PrintFibonacciLoop(int counter)
{
	int Fibonacci, prev1 = 1, prev2 = 0;
	cout << "1  ";
	for (int i = 2; i <= counter; i++)
	{
		Fibonacci = prev1+prev2;
		cout << Fibonacci << "  ";
		prev2 = prev1;
		prev1 = Fibonacci;
	}
	
}

int main()
{
	PrintFibonacciLoop(10);
	return 0;
}