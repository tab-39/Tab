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

bool LocateClientByAccountNumber(string FileName, string AccountToSearch, stClientData& ClientD)
{
	vector <stClientData> vClients = LoadClientsDataFromFile(FileName);
	for (stClientData C :vClients)
	{
		if (C.AccountNumber == AccountToSearch)
		{
			ClientD = C;
			return true;
		}
		
	}
	return false;
}

void PrintClientDataString(stClientData ClientData)
{
	cout << "Account Number: " << ClientData.AccountNumber << endl;
	cout << "PinCode       : " << ClientData.PinCode << endl;
	cout << "Name          : " << ClientData.Name << endl;
	cout << "Phone         : " << ClientData.Phone << endl;
	cout << "AccountBalance: " << ClientData.AccountBalance << endl;
}

int main()
{
	stClientData ClientData;
	string AccountToSearch = InputLib::ReadText("Please enter AccountNumber: ");
	if (LocateClientByAccountNumber("ClientsFile.txt", AccountToSearch, ClientData))
	{
		PrintClientDataString(ClientData);
	}
	else
		cout << "\nClient with Account Number (" << AccountToSearch << ") is Not Found!";
	return 0;
}
