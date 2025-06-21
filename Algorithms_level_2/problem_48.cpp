#include <iostream>
#include <string>
#include <cmath>
using namespace std;


float ReadNumber(string typeOfNumber)
{
    float N;
        cout << "Please enter "<< typeOfNumber <<" : ", cin >> N;
    return N;
}

int MyFloor(float number)
{
    if (number < 0 && number < int(number))
        return number-1;
    return number;
}

int main()
{
    float Number = ReadNumber("Number to Floor it");
    
    cout << "My Floor: " << MyFloor(Number) << endl;
    cout << "C++ Floor: " << floor(Number) << endl;
    return 0;
};
