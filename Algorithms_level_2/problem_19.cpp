#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int RandomNumber(int from, int to)
{
    int RandNumber = rand() % (to - from + 1) + from;
    return RandNumber;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << RandomNumber(3, 6) << endl;
    return 0;
}
