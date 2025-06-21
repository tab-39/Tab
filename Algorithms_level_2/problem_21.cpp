#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enChar {SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

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

int RandomNumber(int from, int to)
{
    int RandNumber = rand() % (to - from + 1) + from;
    return RandNumber;
}


string GenerateWord(enChar TypeChar, int length)
{
    string Key;
        for (int j = 1; j <= length; j++)
    {
        Key += RandomChar(TypeChar);
    }
    return Key;
}

string GenerateKey()
{
    string key;
    for (int i = 1; i <= 4; i++)
    {
        key += GenerateWord(CapitalLetter, 4);
        if (i < 4)
            key += "-";
    }
    
    return key;
}

void PrintKeysByNumber(int counter)
{
    for (int i = 1; i <= counter; i++)
    {
        cout <<  "Key[" << i << "]: " << GenerateKey() << endl;
    }
    
}

int main()
{
    srand((unsigned)time(NULL));

    int CountOfKeys = ReadPositiveNumber("Count Of Keys");
    PrintKeysByNumber(CountOfKeys);
    return 0;
};
