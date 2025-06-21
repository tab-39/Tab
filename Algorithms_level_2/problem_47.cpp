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

int GetFractionPart(float number)
{
    return 10*(number - int(number));
}


int MyRound(float number)
{

    int fraction = GetFractionPart(number);

    if (number > 0)
    {
        if (fraction > 4)
            return number+1;
    }
    else
    {
        if (-fraction > 4)
            return number-1;
    }

    return number;
}



int main()
{
    float Number = ReadNumber("Number to Round it");
    
    cout << "My Round: " << MyRound(Number) << endl;
    cout << "C++ Round: " << round(Number) << endl;
    return 0;
};
