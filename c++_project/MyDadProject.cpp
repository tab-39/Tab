#include <iostream>
using namespace std;

struct stNumberInfo
{
    short number;
    int total = 0;
    int counter = 0;
    int Remainder = 0;
};

short ReadNumberType()
{
    short number;
    cout << "What is number [1]:77, [2]:48: ";
    cin >> number;
    return number;
}

int ConvertToNumber(short number)
{
    if (number == 1)
        return 77;
    else if (number == 2)
        return 48;
    return 0;
}

int Total()
{
    int total;
    cout << "What is Total: ";
    cin >> total;
    return total;
}

void FillCounterAndRemainder(stNumberInfo& NumberInfo)
{
    int Remainder = NumberInfo.total;
    while (Remainder >= NumberInfo.number)
    {
        Remainder -= NumberInfo.number;
        NumberInfo.counter++;
    }
    NumberInfo.Remainder = Remainder;
}

void PrintResults(stNumberInfo NumberInfo)
{
    cout << "The Count Is: " << NumberInfo.counter << endl;
    cout << "The Remainder Is: " << NumberInfo.Remainder;
}

int main()
{
    string ContinueOrNot;
    do
    {
        stNumberInfo NumberInfo;
        NumberInfo.number = ConvertToNumber(ReadNumberType());
        NumberInfo.total = Total();
        FillCounterAndRemainder(NumberInfo);
        PrintResults(NumberInfo);    
        cout << "\nDo you Want to Calculate again? Y/N: ", cin >> ContinueOrNot;
    } while (ContinueOrNot == "y" || ContinueOrNot == "Y");
        return 0;
}
