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
    }while (N > 0);
    return N;
}

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

enPrimeNotPrime CheckPrimeNotPrime(int Number)
{
    int M = round(Number /2);
    for (int counter = 2; counter <= M; counter++)
    {
        if (Number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}


void PrintPrimeNumberFrom1ToN(int N)
{
    for (int i = 1; i <= N; i++)
    {
        if (CheckPrimeNotPrime(i) == enPrimeNotPrime::Prime)
            cout << i << endl;
    }
}


int main()
{
    PrintPrimeNumberFrom1ToN(ReadPositiveNumber("Prime number from 1 to"));
    return 0;
};
