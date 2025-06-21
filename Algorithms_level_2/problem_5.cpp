#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ReadStringNumber(string massage)
{
    string stNumber;
    cout << "Please enter " << massage << " : ", cin >> stNumber;
    return stNumber;
}

string ReversNumber(string stNumber)
{
    string reversedNumber = "";

    for (int i = stNumber.length(); i >= 0 ; i--)
        reversedNumber += stNumber[i];
    
    return reversedNumber;
}


int main()
{
    string stNumber = ReadStringNumber("number to revers it");
    cout << "reversed number is : " << ReversNumber(stNumber);
    return 0;
};
