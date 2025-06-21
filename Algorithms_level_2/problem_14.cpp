#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool CheckPositiveNumber(float number)
{
    if (number > 0 && number < 26)
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

void printInvertedLetterPattern(int number)
{
    for (int i = number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(i+64);
        }
        cout << "\n";
    }
    
}

int main()
{
    int invertedPattern = ReadPositiveNumber("number to do Pattern");
    printInvertedLetterPattern(invertedPattern);
    return 0;
};
