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
void Swap(int& A, int& B)
{ 
    int Temp = A;
    A = B;
    B = Temp;
}
int RandomNumber(int from, int to)
{
    int RandNumber = rand() % (to - from + 1) + from;
    return RandNumber;
}

void PrintArray(int ArrayN[100], int length)
{
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        cout << ArrayN[i] << " ";
    }
    cout << endl;
}

void ToNArray(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = i+1;
    }
}

void ShuffleArray(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        Swap(arr[RandomNumber(1, length)-1], arr[RandomNumber(1, length)-1]);
    }
}
    
int main()
{
    srand((unsigned)time(NULL));
    int elementCounter = ReadPositiveNumber("Element Counter");
    int arr[100];

    cout << "Array1 : ";
    ToNArray(arr, elementCounter);
    PrintArray(arr, elementCounter);

    cout << "Array Shuffled : ";
    ShuffleArray(arr, elementCounter);
    PrintArray(arr, elementCounter);

    return 0;
};
