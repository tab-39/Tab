#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

void PrintFibonacciRecursion(int counter, int prev1, int prev2)
{
	int Fibonacci = 0;
	if (counter > 0)
	{
		Fibonacci = prev1+prev2;
		prev2 = prev1;
		prev1 = Fibonacci;
		cout << Fibonacci << "  ";
		PrintFibonacciRecursion(counter - 1, prev1, prev2);
	}
	
}

int main()
{
	PrintFibonacciRecursion(10, 0, 1);
	return 0;
}
