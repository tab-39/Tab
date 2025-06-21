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

void PrintArray(int ArrayN[10], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << ArrayN[i] << " ";
    }
    cout << endl;
}

bool CheckContinue()
{
    bool Check;

    cout << "Do you want add more numbers? [0]:No, [1]:yes: ", cin >> Check;
    cout << endl;

    return Check;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

void allocateSimiDynimcNumbers(int arr[100], int& length)
{
    for (int i = 0; i < 100; i++)
    {
        AddArrayElement(ReadPositiveNumber("a Number"), arr, length);
        if (!CheckContinue())
        {
            break;
        }
    }
}

int main()
{
    int arr[100], length = 0;

    allocateSimiDynimcNumbers(arr, length);

    cout << "\nArray Length: " << length << endl;
    cout << "Array elements: ";
    PrintArray(arr, length);
    return 0;
};