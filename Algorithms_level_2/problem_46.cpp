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

float MyAbs(float number)
{
    if (number < 0)
        return -number;

    return number;
}



int main()
{
    float Number = ReadNumber("Number to abs it");
    float myAbs = MyAbs(Number);
    float Cabs = abs(Number);
    
    cout << "My Abs: " << myAbs << endl;
    cout << "C++ Abs: " << Cabs << endl;
    return 0;
};
