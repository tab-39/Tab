#include <iostream>
#include <string>
using namespace std;

bool ValidateNumberInRange(float number, float from, float to)
{
    return (number >=from && number <=to);
}
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



struct strInfo
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};


void ReadInfo(strInfo& Info)
{

    cout << "Please enter FirstName?\n";
    cin >> Info.FirstName;

    cout << "Please enter LastName?\n";
    cin >> Info.LastName;

    cout << "Please enter Age?\n";
    cin >> Info.Age;

    cout << "Please enter Phone?\n";
    cin >> Info.Phone;
    cout << "\n\n";


}

void PrintInfo(strInfo Info)
{

    cout << "\n**********************************\n";

    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;

    cout << "**********************************\n\n";


}



void ReadPersonsInfo(strInfo Persons[100],int &NumberOfPersons)
{

    cout << "How many persons?\n";
    cin >> NumberOfPersons;

    for (int i = 0; i <= NumberOfPersons - 1; i++)
    {
        cout << "Please Enter Person's " << i + 1 << " Info: \n";
        ReadInfo(Persons[i]);
    }
}


void PrintPersonsInfo(strInfo Persons[100], int NumberOfPersons)
{
    for (int i = 0; i <= NumberOfPersons - 1; i++)
    {
        cout << "Person's " << i + 1 << " Info: \n";
        PrintInfo(Persons[i]);
    }
    

}



int main()
{

    strInfo Persons[100];
    int NumberOfPersons = 1;

    ReadPersonsInfo(Persons, NumberOfPersons);
    PrintPersonsInfo(Persons, NumberOfPersons);

    return 0;
}