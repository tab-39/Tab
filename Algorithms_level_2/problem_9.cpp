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
string OneOrMore(int Frequency)
{
    if (Frequency > 1)
        return " Times";
    else
        return " Time";
}

int FrequencyOfNumber(int Digits, int Digit)
{
    int Frequency = 0, Remainder;
    while (Digits > 0)
    {
        Remainder = Digits % 10;
        if (Remainder == Digit)
            Frequency++;
        Digits /= 10;
    }
    
    return Frequency;
}

void PrintFrequency(int Digits)
{
    for (int Digit = 0; Digit < 10; Digit++)
    {
        int Frequency = FrequencyOfNumber(Digits, Digit);
        if (Frequency)
        {
            cout << "Digit " << Digit << " Frequency is " << Frequency << OneOrMore(Frequency) << endl;
        }
    }
}

int main()
{
    int Digits = ReadPositiveNumber("Digits");
    PrintFrequency(Digits);
    return 0;
};
