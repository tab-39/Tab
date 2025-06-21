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

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};
enum enChar {SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

int RandomNumber(int from, int to)
{
    int RandNumber = rand() % (to - from + 1) + from;
    return RandNumber;
}

void PrintArray(int ArrayN[100], int length)
{
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

void CopyArrayPrimeNumber(int arr[100], int CopedArray[100], int length, int& lengthOfCopedArray)
{
    lengthOfCopedArray = -1;
    for (int i = 0; i < length; i++)
    {
        if (CheckPrimeNotPrime(arr[i]) == enPrimeNotPrime::Prime)
        {
            lengthOfCopedArray++;
            CopedArray[lengthOfCopedArray] = arr[i];
            
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int elementCounter = ReadPositiveNumber("Element Counter");
    int arr[100], CopedArray[100];

    cout << "Original Array : ";
    RandomArray(arr, elementCounter);
    PrintArray(arr, elementCounter);

    cout << "Coped Array : ";
    int lengthOfCopedArray;
    CopyArrayPrimeNumber(arr, CopedArray, elementCounter, lengthOfCopedArray);
    PrintArray(CopedArray, lengthOfCopedArray);
    return 0;
};
