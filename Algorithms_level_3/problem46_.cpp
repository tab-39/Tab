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
	cout << "Account Number: " << ClientData.AccountNumber << endl;
	cout << "PinCode       : " << ClientData.PinCode << endl;
	cout << "Name          : " << ClientData.Name << endl;
	cout << "Phone         : " << ClientData.Phone << endl;
	cout << "AccountBalance: " << ClientData.AccountBalance << endl;

}

int main()
{
	string ClientData = "A134#//#396061#//#Turki Barayan#//#05703930191#//#5.230000";
	stClientData Client = ConvertLineToRecord(ClientData);
	cout << "Line Record is: \n" << ClientData << endl;
	cout << "The following is the extracted client record: \n";
	PrintClientDataString(Client);
	return 0;
}