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
        Key += char(RandomNumber(65, 90));
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

void FillArrayByKeys(string arr[100], int counter)
{
    for (int i = 0; i < counter; i++)
    {
        arr[i] = GenerateKey();
    }
    
}

void PrintStringArray(string ArrayN[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Array["<< i <<"]: " << ArrayN[i] << endl;
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int CountOfKeys = ReadPositiveNumber("Count Of Keys");
    string ArrayOfKeys[100];
    FillArrayByKeys(ArrayOfKeys, CountOfKeys);
    PrintArray(ArrayOfKeys, CountOfKeys);
    return 0;
};
