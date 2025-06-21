#include <iostream>
#include <string>
using namespace std;

class clsCalculator
{
    int _Result = 0;
    int _LastNumber = 0;
    string _LastOperation = "Clear";

public:
    void PrintResult()
    {   
        cout << "Result After " << _LastOperation << " " << _LastNumber << " is: " << _Result << endl;
    }
    void Clear()
    {
        _LastNumber = 0;
        _Result = 0;
        _LastOperation = "Clear";
    }
    void Add(int Number)
    {
        _LastOperation = "Add";
        _LastNumber = Number;
        _Result += Number;
    }
    void Subtract(int Number)
    {
        _LastOperation = "Subtract";
        _LastNumber = Number;
        _Result -= Number;
    }
    void Multiply(int Number)
    {
        _LastOperation = "Multiply";
        _LastNumber = Number;
        _Result *= Number;
    }
    void Divid(int Number)
    {
        if (Number == 0)
        {
            Number = 1;
        }
        _LastOperation = "Divid";
        _LastNumber = Number;
        _Result /= Number;
    }
    void CancelLastOperation()
    {
        if (_LastOperation == "Divid")
        {
            _Result *= _LastNumber;
            _LastOperation = "Multiply";
        }
        else if (_LastOperation == "Multiply")
        {
            _Result /= _LastNumber;
            _LastOperation = "Divid";
        }
        else if (_LastOperation == "Subtract")
        {
            _Result += _LastNumber;
            _LastOperation = "Add";
        }
        else if (_LastOperation == "Add")
        {
            _Result -= _LastNumber;
            _LastOperation = "Subtract";
        }
    }
};

int main()
{
    clsCalculator Calculator1;
    Calculator1.Clear();
    
    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();
    
    Calculator1.Subtract(20);
    Calculator1.PrintResult();
    
    Calculator1.Divid(0);
    Calculator1.PrintResult();
    
    Calculator1.Multiply(3);
    Calculator1.PrintResult();
    
    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    return 0;
}
