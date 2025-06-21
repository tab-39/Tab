#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int ReadNumber(string massage)
{
    int stNumber;
    cout << "Please enter " << massage << " : ", cin >> stNumber;
    return stNumber;
}

int ReversNumber(int Number)
{
    float ReversedNumber, remainder;
    while (Number > 0)
    {
        remainder = Number % 10;
        Number /=10;
        ReversedNumber *= 10;
        ReversedNumber += remainder;
    }
    return ReversedNumber;
}



int main()
{
    int reversedNumber = ReversNumber(ReadNumber("number to revers it"));
    cout << "Reversed number is : " << reversedNumber;
    return 0;
};
