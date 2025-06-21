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

void CopyAndReveresArray(int arr[100], int CopedArray[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        CopedArray[length-i-1] = arr[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int elementCounter = ReadPositiveNumber("Element Counter");
    int arr[100], CopedArray[100];

    cout << "Original Array: " << endl;
    RandomArray(arr, elementCounter);
    PrintArray(arr, elementCounter);

    cout << "Coped And Reversed Array: " << endl;
    CopyAndReveresArray(arr, CopedArray, elementCounter);
    PrintArray(CopedArray, elementCounter);
    return 0;
};
