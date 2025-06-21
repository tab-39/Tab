#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enChar {SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

int RandomNumber(int from, int to)
{
    int RandNumber = rand() % (to - from + 1) + from;
    return RandNumber;
}

char RandomChar(enChar CharType)
{
    char Char;
    switch (CharType)
    {
    case enChar::SmallLetter:
        Char = RandomNumber(97, 122);
        return Char;
    case enChar::CapitalLetter:
        Char = RandomNumber(65, 91);
        return Char;
    case enChar::SpecialCharacter:
        Char = RandomNumber(33, 47);
        return Char;
    case enChar::Digit:
        Char = RandomNumber(48, 57);
        return Char;
    }
    return 0;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << RandomChar(SmallLetter) << endl;
    cout << RandomChar(CapitalLetter) << endl;
    cout << RandomChar(SpecialCharacter) << endl;
    cout << RandomChar(Digit) << endl;
    return 0;
};
