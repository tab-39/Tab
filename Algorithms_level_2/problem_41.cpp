#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ReversNumber(int Number)
{
    float ReversedNumber, remainder;
    while (Number)
    {
        remainder = Number % 10;
        Number /=10;
        ReversedNumber *= 10;
        ReversedNumber += remainder;
    }
    return ReversedNumber;
}
bool CheckPalindrome(int number)
{
    return number == ReversNumber(number);
}

void PrintArray(int ArrayN[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << ArrayN[i] << " ";
    }
    cout << endl;
}

bool IsPalindromeArray(int ArrayN[100], int length)
{

    int Counter = length / 2;

    for (int i = 0; i < Counter; i++)
    {
        if (ArrayN[i] != ArrayN[length-i-1])
        {
            return false;
        }
    } 
    return true;
}

int main()
{
    int arr[100] = {10, 20, 30, 40, 30, 20, 10}, length = 7;
    bool IsPalindrome = IsPalindromeArray(arr, length);

    cout << "Array element: \n";
    PrintArray(arr, length);

    if (IsPalindrome)
        cout << "\nYes array is Palindrome";
    else
        cout << "\nNo array is not Palindrome";
    
    return 0;
};
