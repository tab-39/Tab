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

float Sum(int number)
{
    float sumOfNumber, Remainder;
    while (number > 0)
    {
        Remainder = number % 10;
        number /= 10;
        sumOfNumber += Remainder;
    }
    return sumOfNumber;
}


int main()
{
    int number = ReadPositiveNumber("number to sum");
    cout << "Sum of Digits: " << Sum(number);
    return 0;
};
