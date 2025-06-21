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

int MyCeil(float number)
{
    if (number > 0 && number > int(number))
        return number+1;

    return number;
}

int main()
{
    float Number = ReadNumber("Number to Ceil it");
    
    cout << "My Ceil: " << MyCeil(Number) << endl;
    cout << "C++ Ceil: " << ceil(Number) << endl;
    return 0;
};
