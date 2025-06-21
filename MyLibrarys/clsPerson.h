#pragma once
#include<iostream>
using namespace std;

class clsPerson
{

    class clsAddress
    {
        private:
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;
        public:
        clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country = Country;
        }
        void Print()
        {
            cout << "Address:" << endl;
            cout << "Addressline1: " << _AddressLine1 << endl;
            cout << "Addressline2: " << _AddressLine2 << endl;
            cout << "City: " << _City << endl;
            cout << "Country: " << _Country << endl;
        }
    };
    string _FullName;
    public:
    clsAddress Address = clsAddress("", "", "", "");

    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
    {
        _FullName = FullName;
        Address = clsAddress(AddressLine1, AddressLine2, City, Country);
    }

};
