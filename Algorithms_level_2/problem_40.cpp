#include <iostream>
#include <string>
#include <cmath>
using namespace std;


bool in(int arr[100], int object, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == object)
        {
            return true;
        }
        
    }
    return false;
}

void PrintArray(int ArrayN[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << ArrayN[i] << " ";
    }
    cout << endl;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

void CopyDistanceNumbersToArray(int arr[100], int arr2[100], int length, int& length2)
{
    for (int i = 0; i < length; i++)
    {
        if (!in(arr2, arr[i], length2))
        {
            AddArrayElement(arr[i], arr2, length2);
        }
        
    }    
}

int main()
{
    int arr[10] = {10, 20, 10, 50, 20, 30, 50, 60, 60, 90}, length = 10;
    int arr2[10], length2 = 0;

    CopyDistanceNumbersToArray(arr, arr2, length, length2);

    cout << "Array1 elements: " << endl;
    PrintArray(arr, length);

    cout << "Array2 elements: " << endl;
    PrintArray(arr2, length2);
    return 0;
};
