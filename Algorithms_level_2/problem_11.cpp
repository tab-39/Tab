#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool CheckPositiveNumber(float number)
{
    if (number > 0)
        return true;
    else
        return false;
}
float ReadPositiveNumber(string typeOfNumber)
{
    float N;
    do
    {
        cout << "Please enter "<< typeOfNumber <<" : ", cin >> N;
    }while (!CheckPositiveNumber(N));
    return N;
}
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

int main()
{
    int number = ReadPositiveNumber("number to check palindrome");
    
    if (CheckPalindrome(number))
        cout << "Yes, it is a Palindrome number.";
    else
        cout << "No, it is NOT a Palindrome number.";    
    return 0;
};
