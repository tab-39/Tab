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

void PrintArray(int ArrayN[10], int length)
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

bool in(int arr[100], int object, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == object)
        {
            return true;
        }
        
    }
    return false;
}

int main()
{
    srand((unsigned)time(NULL));
    int elementCounter = ReadPositiveNumber("Element Counter");
    int arr[100], objectToSearch;

    RandomArray(arr, elementCounter);
    cout << "Original array: " << endl;
    PrintArray(arr, elementCounter);

    objectToSearch = ReadPositiveNumber("number to search for");

    cout << "Number you are looking for is: " << objectToSearch << endl;

    if (in(arr, objectToSearch, elementCounter))
    {
        cout << "Yes, The number in found: "<< endl;
    }
    else
        cout << "No, The number is not found :-(";
    return 0;
};

