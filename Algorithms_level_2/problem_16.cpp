#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void PrintAllCharacterPassword()
{   
    string guess = "";
    for (int letter1 = 65; letter1 <= 90; letter1++)
    {
        for (int letter2 = 65; letter2 <= 90;letter2++)
        {
            for (int letter3 = 65; letter3 <= 90; letter3++)
            {
                guess += char(letter1);
                guess += char(letter2);
                guess += char(letter3);
                cout << guess << endl;
                guess = "";
            }
        }
    }
}


int main()
{
    PrintAllCharacterPassword();
    return 0;
};
