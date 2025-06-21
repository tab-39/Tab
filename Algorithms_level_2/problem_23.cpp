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

enum enChar {SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

int RandomNumber(int from, int to)
{
    int RandNumber = rand() % (to - from + 1) + from;
    return RandNumber;
}

void PrintArray(int ArrayN[10], int length)
{
    cout << "Original array: ";
    for (int i = 0; i < length; i++)
    {
        cout << ArrayN[i] << " ";
    }
    cout << endl;
}

void RandomArray(int arr[100], int elementCounter)
{
    for (int i = 0; i < elementCounter; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }    
}

int main()
{
    srand((unsigned)time(NULL));
    int elementCounter = ReadPositiveNumber("Element Counter");
    int arr[100];

    RandomArray(arr, elementCounter);

    PrintArray(arr, elementCounter);
    return 0;
};
