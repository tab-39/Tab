#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
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
	cout << "The following are the client details: \n\n";
	cout << "Account Number: " << ClientData.AccountNumber << endl;
	cout << "PinCode       : " << ClientData.PinCode << endl;
	cout << "Name          : " << ClientData.Name << endl;
	cout << "Phone         : " << ClientData.Phone << endl;
	cout << "AccountBalance: " << ClientData.AccountBalance << endl;
}

bool DeleteOrNot()
{
	string DeleteOrNo;
	cout << "Are you sure you want delete this client (1/0): ";
	cin >> DeleteOrNo;
	if (DeleteOrNo == "Y" || DeleteOrNo == "y" || DeleteOrNo == "1")
	{
		return true;
	}
	return false;
}

vector <stClientData> CreateNewVectorAndDelete(string FileName, string AccountToSearch)
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
				if (!DeleteOrNot())
				{
					vClient.push_back(ClientData);
				}
			}
		}
    	MyFile.close();
    }
	return vClient;
}

void DeleteClientByAccountNumber(string FileName, string AccountToSearch)
{
	vector <stClientData> NewClient = CreateNewVectorAndDelete(FileName, AccountToSearch);
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
	DeleteClientByAccountNumber("ClientsFile.txt", AccountToSearch);
	return 0;
}
