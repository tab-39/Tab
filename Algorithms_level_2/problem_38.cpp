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

void AddOddArrayElement(int Number, int arr[100], int& arrLength)
{
    if (Number % 2 != 0)
    {
        arr[arrLength] = Number;
        arrLength++;
    }
}

void CopyArray(int arr[100], int CopedArray[100], int length, int& length2)
{
    for (int i = 0; i < length; i++)
        AddOddArrayElement(arr[i], CopedArray, length2);
}

int main()
{
    srand((unsigned)time(NULL));
    int elementCounter = ReadPositiveNumber("Element Counter");
    int arr[100], CopedArray[100], length2=0;

    cout << "Original Array : ";
    RandomArray(arr, elementCounter);
    PrintArray(arr, elementCounter);

    cout << "Coped Array : ";
    CopyArray(arr, CopedArray, elementCounter, length2);
    PrintArray(CopedArray, length2);
    return 0;
};
