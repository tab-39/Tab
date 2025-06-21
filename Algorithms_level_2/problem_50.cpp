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

float MySqrt(int number)
{
    return pow(number, 0.5);
}

int main()
{
    int Number = ReadNumber("Number to Sqrt it");
    
    cout << "My Sqrt: " << MySqrt(Number) << endl;
    cout << "C++ Sqrt: " << sqrt(Number) << endl;
    return 0;
};
