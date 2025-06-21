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
bool IsPerfect(int number)
{
    int sumN = 0;
    for (int i = 1; i <= (number/2); i++)
    {
        if (number % i == 0)
            sumN += i;
    }
    if (sumN == number)
    {
        return true;
    }
    else 
        return false;
}
void PrintIsPerfect(bool IsPerfect)
{
    if (IsPerfect)
        cout << "is perfect";
    else 
        cout << "is not perfect";
}

void PrintPerfectNumberFrom1ToN(int number)
{
    for (int i = 1; i <= number; i++)
    {
        if (IsPerfect(i))
            cout << i << "\n";
    }
}

int main()
{
    PrintPerfectNumberFrom1ToN(ReadPositiveNumber("Perfect number"));
    return 0;
};
