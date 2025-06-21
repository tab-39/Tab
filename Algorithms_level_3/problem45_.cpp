#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/MathLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

stClientData ReadNewClient()
{
	stClientData ClientData;
	ClientData.AccountNumber = InputLib::ReadText("Enter Account Number: ");
	ClientData.PinCode = InputLib::ReadText("Enter PinCode: ");
	ClientData.Name = InputLib::ReadText("Enter Name: ");
	ClientData.Phone = InputLib::ReadText("Enter Phone: ");
	ClientData.AccountBalance = InputLib::ReadPositiveNumber("Account Balance");
	return ClientData;
}

string ConvertRecordToLine(stClientData Client, string Separator = "#//#")
{
	string RecordLine = "";
	RecordLine += Client.AccountNumber + Separator;
	RecordLine += Client.PinCode + Separator;
	RecordLine += Client.Name + Separator;
	RecordLine += Client.Phone + Separator;
	RecordLine += to_string(Client.AccountBalance);
	return RecordLine;
}

int main()
{
	cout << "Please Enter Client Data: \n\n";
	stClientData ClientData;
	ClientData = ReadNewClient();

	cout << "Client Record for Saving is: \n";
	cout << ConvertRecordToLine(ClientData);
	return 0;
}
