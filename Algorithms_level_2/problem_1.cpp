#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void PrintTableHeader()
{    cout << "\t\t\tMultiplication Table From 1 to 10\n";
    for (int i = 1; i < 11; i++)
    {
        cout << "\t" << i;
    }
    cout << "\n__________________________________________________________________________________\n";
}

string ColumSeparator(int number)
{
    if (number >= 10)
        return "  |";
    else
        return "   |";
}

void PrintMultiplicationTable1to10()
{
    PrintTableHeader();
    for (int y = 1; y < 11; y++)
    {
        cout << y << ColumSeparator(y);
        for (int j = 1; j < 11; j++)
        {
            cout << "\t" << y*j;
        }
        cout << "\n";
    }
}

int main()
{
    PrintMultiplicationTable1to10();
    return 0;
};

