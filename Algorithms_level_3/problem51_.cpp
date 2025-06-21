#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

stClientData ReadNewClient()
{
    stClientData ClientData;
    ClientData.PinCode = InputLib::ReadText("Enter PinCode: ");
    ClientData.Name = InputLib::ReadText("Enter Name: ");
    ClientData.Phone = InputLib::ReadText("Enter Phone: ");
    ClientData.AccountBalance = InputLib::ReadPositiveNumber("Account Balance");
    return ClientData;
}

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
	cout << "The following are the client details: \n\n";
	cout << "Account Number: " << ClientData.AccountNumber << endl;
	cout << "PinCode       : " << ClientData.PinCode << endl;
	cout << "Name          : " << ClientData.Name << endl;
	cout << "Phone         : " << ClientData.Phone << endl;
	cout << "AccountBalance: " << ClientData.AccountBalance << endl;
}

bool UpdateOrNot()
{
	string UpdateOrNo;
	cout << "Are you sure you want Update this client (1/0): ";
	cin >> UpdateOrNo;
	if (UpdateOrNo == "Y" || UpdateOrNo == "y" || UpdateOrNo == "1")
	{
		return true;
	}
	return false;
}

vector <stClientData> CreateNewUpdatedVector(string FileName, string AccountToSearch)
{
	stClientData ClientData;
	fstream MyFile;
	vector <stClientData> vClient;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {	
		string Client;
		while (getline(MyFile, Client))
		{
			ClientData = ConvertLineToRecord(Client);
			if (!(ClientData.AccountNumber == AccountToSearch))
			{	
				vClient.push_back(ClientData);
			}
			else
			{
				PrintClientDataString(ClientData);
				if (UpdateOrNot())
				{
					stClientData UpdatedClient = ReadNewClient();
					UpdatedClient.AccountNumber = AccountToSearch;
					vClient.push_back(UpdatedClient);
					cout << "Client Updated successfully";
				}
			}
		}
    	MyFile.close();
    }
	return vClient;
}

void UpdateClientByAccountNumber(string FileName, string AccountToSearch)
{
	vector <stClientData> NewClient = CreateNewUpdatedVector(FileName, AccountToSearch);
	fstream MyFile;
	vector <stClientData> vClient;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
		for (stClientData & C : NewClient)
		{
			MyFile << MyLib::ConvertRecordToLine(C) << "\n";
		}
	}
}

int main()
{
	string AccountToSearch = InputLib::ReadText("Please enter AccountNumber: ");
	UpdateClientByAccountNumber("ClientsFile.txt", AccountToSearch);
	return 0;
}
