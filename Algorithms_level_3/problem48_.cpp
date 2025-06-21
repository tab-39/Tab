#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

stClientData ConvertLineToRecord(string ClientData)
{
	stClientData Client;
	vector <string> vClient;
	vClient = MyLib::Split(ClientData, "#//#");
	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);
	return Client;
}

void PrintClientDataString(stClientData ClientData)
{
	cout << "| " << setw(20) << left << ClientData.AccountNumber;
	cout << "| " << setw(10) << left << ClientData.PinCode;
	cout << "| " << setw(20) << left << ClientData.Name;
	cout << "| " << setw(15) << left << ClientData.Phone;
	cout << "| " << setw(12) << left << ClientData.AccountBalance;
	cout << "\n";
}

void PrintBar(string FileName)
{
	cout << "______________________________________________________________________________________\n\n";
	cout << "| " << setw(20) << left << "Account Number";
	cout << "| " << setw(10) << left << "Pin Code";
	cout << "| " << setw(20) << left << "Client Name";
	cout << "| " << setw(15) << left << "Phone";
	cout << "| " << setw(12) << left << "Balance";
	cout << "\n______________________________________________________________________________________\n";
}

vector <stClientData> LoadClientsDataFromFile(string FileName)
{
	stClientData ClientData;
	vector <stClientData> ClientsData;
	fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {	
		string Client;
		while (getline(MyFile, Client))
		{
			ClientData = ConvertLineToRecord(Client);
			ClientsData.push_back(ClientData);
		}
    	MyFile.close();
    }
	return ClientsData;
}

void PrintClientsData(string FileName)
{
	vector <stClientData> ClientsData = LoadClientsDataFromFile(FileName);
	cout << "\t\t\tClient List ( " << ClientsData.size() << " ) Client(s).\n";
	PrintBar(FileName);
	for (stClientData client : ClientsData)
	{
		PrintClientDataString(client);
	}
	cout << "\n______________________________________________________________________________________\n";
}

int main()
{
	PrintClientsData("ClientsFile.txt");
	return 0;
}
