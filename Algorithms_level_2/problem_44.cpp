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
    int RandNumber;
    do
    {
        RandNumber = rand() % (to - from + 1) + from;

    } while (RandNumber == 0);

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
        arr[i] = RandomNumber(-100, 100);
    }    
}

int CountPositiveArray(int arr[100], int length)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
            counter++;
        
    }
    return counter;
}

int main()
{
    srand((unsigned)time(NULL));
    int elementCounter = ReadPositiveNumber("Element Counter");
    int arr[100];

    cout << "Original Array : ";
    RandomArray(arr, elementCounter);
    PrintArray(arr, elementCounter);

    cout << "Count Of Positive Numbers In Array: ";
    cout << CountPositiveArray(arr, elementCounter) << endl;
    return 0;
};
