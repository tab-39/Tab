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

string OneOrMore(int Frequency)
{
    if (Frequency > 1)
        return " Times";
    else
        return " Time";
}

void ReadArray(int Element[100], int elementCounter)
{
    for (int i = 0; i < elementCounter; i++)
    {
        cout << "Element [" << i+1 << "]: ";
        cin >> Element[i];
    }
}

void PrintArray(int ArrayN[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << ArrayN[i] << " ";
    }
    cout << endl;
}

int FrequencyOfNumberInArray(int arr[100], int Number, int length)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (Number == arr[i])
        {
            counter++;
        }
        
    }
    return counter;
}

int main()
{
    int Element[100];
    int elementCounter = ReadPositiveNumber("Element Counter");
    
    ReadArray(Element, elementCounter);

    int NumberToCheckFrequency = ReadPositiveNumber("Number You Want To Check");

    PrintArray(Element, elementCounter);
    
    int Frequency = FrequencyOfNumberInArray(Element, NumberToCheckFrequency, elementCounter);

    cout << NumberToCheckFrequency << " is repeated " << Frequency << OneOrMore(Frequency);
    return 0;
};
