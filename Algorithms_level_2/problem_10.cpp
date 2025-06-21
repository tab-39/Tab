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
    while (Number > 0)
    {
        remainder = Number % 10;
        Number /=10;
        ReversedNumber *= 10;
        ReversedNumber += remainder;
    }
    return ReversedNumber;
}

void PrintNumberInOrder(int number)
{
    int ReversedNumber = ReversNumber(number), remainder;
    while (ReversedNumber)
    {
        remainder = ReversedNumber % 10;
        cout << remainder << endl;
        ReversedNumber /= 10;
    }
    
}


int main()
{
    int number = ReadPositiveNumber("number to print it in order");
    PrintNumberInOrder(number);
    return 0;
};
