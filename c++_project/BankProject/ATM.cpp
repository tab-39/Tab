#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
using namespace std;
const string FileName = "ClientsFileBank.txt";
void Login();
void StartScreenMenu();
void QuickWithdrawBalance();
void ResetScreenMenu()
{
    cout << "\nPress any key to go back to main menu... ";
    system("pause>0");
    system("cls");
    StartScreenMenu();
}
struct stClient
{
    string AccountNumber, PinCode, Name, Phone;
    double AccountBalance;
};
stClient CurrentClient;
enum enMenu{QuickWithdraw = 1, NormalWithdraw = 2, Deposit = 3, CheckBalance = 4, Logout = 5};
enum enQuickChoice{Fifty = 1, Hundred = 2, TwoHundred = 3, ThreeHundred = 4, FiveHundred = 5, EightHundred = 6, Thousand = 7, TwoThousand = 8, Exit = 9};
void PrintNormalWithdrawScreen()
{
    cout << "=============================================================\n";
    cout << "                 Normal Withdraw Screen                      \n";
    cout << "=============================================================\n";
}
void PrintQuickWithdrawScreen()
{
    cout << "=============================================================\n";
    cout << "                 Quick Withdraw Screen                      \n";
    cout << "=============================================================\n";
    cout << left << setw(24) << "\t[1] 50"   << setw(10) << "[2] 100" << endl;
    cout << left << setw(24) << "\t[3] 200"  << setw(10) << "[4] 300" << endl;
    cout << left << setw(24) << "\t[5] 500"  << setw(10) << "[6] 800" << endl;
    cout << left << setw(24) << "\t[7] 1000" << setw(10) << "[8] 2000" << endl;
    cout << left << setw(24) << "\t[9] Exit" << endl;
    cout << "=============================================================\n";
}
void PrintDepositScreen()
{
    cout << "=============================================================\n";
    cout << "                      Deposit Screen                      \n";
    cout << "=============================================================\n";
}
void PrintCheckBalanceScreen()
{
    cout << "=============================================================\n";
    cout << "                 Check Balance Screen                      \n";
    cout << "=============================================================\n";
    cout << "Balance is: " << CurrentClient.AccountBalance << endl;
}
bool Perform()
{
	string DeleteOrNo;
	cout << "Are you sure you want perform this Transaction (y/n): ";
	cin >> DeleteOrNo;
	if (DeleteOrNo == "Y" || DeleteOrNo == "y" || DeleteOrNo == "1")
	{
		return true;
	}
	return false;
}
float ReadPositiveNumber(string typeOfNumber)
{
    float N;
    do
    {
        cout << "Enter "<< typeOfNumber <<": ", cin >> N;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid number: ", cin >> N;
        }
        
    }while (N < 0);
    return N;
}
vector<string> Split(string text, string delim = " ")
{
    vector <string> vText;
    int counter = 0;
    short pos = 0;
    string sWord = "";
    while ((pos = text.find(delim)) != std::string::npos)
    {
        sWord = text.substr(0, pos);
        if (sWord != "")
        {
            vText.push_back(sWord);
        }
        text.erase(0, pos+delim.length());
    }
    if (text != "")
    {
        vText.push_back(text);
    }
    return vText;
}
stClient ConvertLineToRecord(string ClientData)
{
	stClient Client;
	vector <string> vClient;
	vClient = Split(ClientData, "#//#");
	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);
	return Client;
}
string ConvertRecordToLine(stClient Client, string Separator = "#//#")
{
    string RecordLine = "";
    RecordLine += Client.AccountNumber + Separator;
    RecordLine += Client.PinCode + Separator;
    RecordLine += Client.Name + Separator;
    RecordLine += Client.Phone + Separator;
    RecordLine += to_string(Client.AccountBalance);
    return RecordLine;
}
vector <stClient> LoadClientsDataFromFile()
{
	stClient ClientData;
	vector <stClient> ClientsData;
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
bool FindUserByUserNameAndPassword(string UserName, string Password, stClient& User)
{
    vector <stClient> vClients = LoadClientsDataFromFile();
    for (stClient U : vClients)
    {
        if (U.AccountNumber == UserName && U.PinCode == Password)
        {
            User = U;
            return true;
        }
    }
    return false;
}
bool LoadUserInfo(string UserName, string Password)
{
    if (FindUserByUserNameAndPassword(UserName, Password, CurrentClient))
        return true;
    return false;
}
vector <stClient> CreateNewUpdatedVector()
{
	stClient ClientData;
	fstream MyFile;
	vector <stClient> vClient;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {	
		string Client;
		while (getline(MyFile, Client))
		{
			ClientData = ConvertLineToRecord(Client);
			if (!(ClientData.AccountNumber == CurrentClient.AccountNumber))
			{	
				vClient.push_back(ClientData);
			}
			else
			{
                ClientData.AccountBalance = CurrentClient.AccountBalance;
				vClient.push_back(ClientData);
			}
		}
    	MyFile.close();
    }
	return vClient;
}
void UpdateClientBalanceFromFile()
{
	vector <stClient> NewClient = CreateNewUpdatedVector();
	fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
		for (stClient & C : NewClient)
		{
			MyFile << ConvertRecordToLine(C) << "\n";
		}
	}
}
void LogoutProgram()
{
    UpdateClientBalanceFromFile();
    system("cls");
    Login();
}
void Withdraw(int WithdrawAmount)
{
    if (WithdrawAmount > CurrentClient.AccountBalance) 
    {   
        cout << "Insufficient balance. Please enter a smaller amount than "<< CurrentClient.AccountBalance << " ." << endl;
        cout << "\nPress any key to continue... ";
        system("pause>0");
        system("cls");
        PrintQuickWithdrawScreen();
        QuickWithdrawBalance();
    }
    if (Perform())
    {
        CurrentClient.AccountBalance -= WithdrawAmount;
        cout << "Done Successfully. New balance is: " << CurrentClient.AccountBalance;
    }
    else
        cout << "Ok No Problem.";
}

void QuickWithdrawBalance()
{
    cout << "Balance is: "<< CurrentClient.AccountBalance << endl;
    int QuickChoice = ReadPositiveNumber("Withdraw Choose From [1] to [9]");
    switch (QuickChoice)
    {
    case enQuickChoice::Fifty:
        Withdraw(50);
        break;
    case enQuickChoice::Hundred:
        Withdraw(100);
        break;
    case enQuickChoice::TwoHundred:
        Withdraw(200);
        break;
    case enQuickChoice::ThreeHundred:
        Withdraw(300);
        break;
    case enQuickChoice::FiveHundred:
        Withdraw(500);
        break;
    case enQuickChoice::EightHundred:
        Withdraw(800);
        break;
    case enQuickChoice::Thousand:
        Withdraw(1000);
        break;
    case enQuickChoice::TwoThousand:
        Withdraw(2000);
        break;
    case enQuickChoice::Exit:
        StartScreenMenu();
        break;
    default:
        break;
    }
}
void DepositBalance()
{
    int DepositAmount;
    do
    {
        DepositAmount = ReadPositiveNumber("an amount multiple of 5's");
        if (DepositAmount % 5 != 0) 
            cout << "Invalid amount. Please enter a multiple of 5." << endl;
    } while (DepositAmount % 5 != 0);

    if (Perform())
    {
        CurrentClient.AccountBalance += DepositAmount;
        cout << "Done Successfully. New balance is: " << CurrentClient.AccountBalance;
    }
    else
        cout << "Ok No Problem.";
}
void WithdrawBalance()
{
    int WithdrawAmount;
    do
    {
        WithdrawAmount = ReadPositiveNumber("an amount multiple of 5's");

        if (WithdrawAmount % 5 != 0) 
            cout << "Invalid amount. Please enter a multiple of 5." << endl;
        else if (WithdrawAmount > CurrentClient.AccountBalance) 
            cout << "Insufficient balance. Please enter a smaller amount than "<< CurrentClient.AccountBalance << " ." << endl;

    } while (WithdrawAmount % 5 != 0 || WithdrawAmount > CurrentClient.AccountBalance);

    if (Perform())
    {
        CurrentClient.AccountBalance -= WithdrawAmount;
        cout << "Done Successfully. New balance is: " << CurrentClient.AccountBalance;
    }
    else
        cout << "Ok No Problem.";
}

void MyChoice(enMenu MenuChoice)
{
    switch (MenuChoice)
    {
    case enMenu::QuickWithdraw:
        system("cls");
        PrintQuickWithdrawScreen();
        QuickWithdrawBalance();
        UpdateClientBalanceFromFile();
        ResetScreenMenu();
        break;
    case enMenu::NormalWithdraw:
        system("cls");
        PrintNormalWithdrawScreen();
        WithdrawBalance();
        UpdateClientBalanceFromFile();
        ResetScreenMenu();
        break;
    case enMenu::Deposit:
        system("cls");
        PrintDepositScreen();
        DepositBalance();
        UpdateClientBalanceFromFile();
        ResetScreenMenu();
        break;
    case enMenu::CheckBalance:
        system("cls");
        PrintCheckBalanceScreen();
        ResetScreenMenu();
        break;
    case enMenu::Logout:
        system("cls");
        UpdateClientBalanceFromFile();
        LogoutProgram();
        break;
    default:
        break;
    }
}
enMenu ScreenMenuChoice()
{
    system("cls");
    short number = 0;
    cout << "=============================================================\n";
    cout << "                 ATM Main Menu Screen                           \n";
    cout << "=============================================================\n";
    cout << left << setw(37) << "\t[1]Quick Withdraw." << endl;
    cout << left << setw(37) << "\t[2]Normal Withdraw." << endl;
    cout << left << setw(37) << "\t[3]Deposit." << endl;
    cout << left << setw(37) << "\t[4]Check Balance." << endl;
    cout << left << setw(37) << "\t[5]Logout." << endl;
    cout << "=============================================================\n";
    cout << "Choose what do you want to do: [1 to 5]: ";
    cin >> number;
    return enMenu(number);
}
void StartScreenMenu()
{
    MyChoice(ScreenMenuChoice());
}
void Login()
{
    bool LoginFeild = false;
    string AccountNumber, PinCode;
    do
    {
        system("cls");
        cout << "--------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n--------------------------\n";
        if (LoginFeild)
        {
            cout << "Invalid AccountNumber/PinCode!\n";
        }
        cout << "Enter AccountNumber: ";
        cin >> AccountNumber;

        cout << "Enter PinCode: ";
        cin >> PinCode;
        LoginFeild = !LoadUserInfo(AccountNumber, PinCode);
    } while (LoginFeild);
    StartScreenMenu();
}

int main()
{
    Login();
    return 0;
}

