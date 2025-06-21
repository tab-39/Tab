#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
using namespace std;

const string FileName = "ClientsFileBank.txt";
const string UsersFileName = "Users.txt";
enum enMenu{ShowClient = 1, AddClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5,Transactions = 6, ManageUsers = 7, Logout = 8};
enum enTMenu{Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenu = 4};
enum enManageUserMenu{ShowUser = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, BackMain = 6};
enum enMainMenuPermissions{eAll = -1, eShowClient = 1, eAddClient = 2, eDeleteClient = 4, eUpdateClient = 8, eFindClient = 16,eTransactions = 32, eManageUsers = 64};
void Login();
void StartScreenMenu();
void StartTransactionsScreenMenu();
void StartUserManageScreenMenu();
void ResetScreenMenu()
{
    cout << "\nPress any key to go back to main menu... ";
    system("pause>0");
    system("cls");
    StartScreenMenu();
}
void ResetScreenUserMenu()
{
    cout << "\nPress any key to go back to Manage User Menu... ";
    system("pause>0");
    system("cls");
    StartUserManageScreenMenu();
}

void ResetScreenTransactionsMenu()
{
    cout << "\nPress any key to go back to Transactions menu... ";
    system("pause>0");
    system("cls");
    StartTransactionsScreenMenu();
}

struct stClient
{
    string AccountNumber, PinCode, Name, Phone;
    double AccountBalance;
};

struct stUser
{
    string UserName, Password;
    short Permissions;
};

stUser CurrentUser;

char ReadChar(string massage)
{
    char character;
    cout << massage, cin >> character;
    return character;
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

string ReadText(string massage)
{
    string text;
    cout << massage;
    getline(cin >> ws, text);
    return text;
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

string ConvertRecordToLineUsers(stUser User, string Separator = "#//#")
{
    string RecordLine = "";
    RecordLine += User.UserName + Separator;
    RecordLine += User.Password + Separator;
    RecordLine += to_string(User.Permissions);
    return RecordLine;
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

stUser ConvertLineToRecordUsers(string UserData)
{
	stUser User;
	vector <string> vUsers;
	vUsers = Split(UserData, "#//#");
	User.UserName = vUsers[0];
	User.Password = vUsers[1];
	User.Permissions = stod(vUsers[2]);
	return User;
}

vector <stClient> LoadClientsDataFromFile(string FileName)
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

vector <stUser> LoadUsersDataFromFile(string FileName)
{
	stUser UserData;
	vector <stUser> UsersData;
	fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {	
	string User;
	while (getline(MyFile, User))
	{
		UserData = ConvertLineToRecordUsers(User);
		UsersData.push_back(UserData);
	}
    MyFile.close();
    }
	return UsersData;
}

void PrintClient(stClient ClientData)
{
	cout << "Account Number: " << ClientData.AccountNumber << endl;
	cout << "PinCode       : " << ClientData.PinCode << endl;
	cout << "Name          : " << ClientData.Name << endl;
	cout << "Phone         : " << ClientData.Phone << endl;
	cout << "AccountBalance: " << ClientData.AccountBalance << endl;
}

void PrintUser(stUser UserData)
{
	cout << "User Name  : " << UserData.UserName << endl;
	cout << "Password   : " << UserData.Password << endl;
	cout << "Permissions: " << UserData.Permissions << endl;
}

void PrintDepositAndWithdrawScreen(bool Deposit)
{
    if (Deposit)
    {
        cout << "----------------------------------\n";
        cout << "          Deposit Screen          \n";
        cout << "----------------------------------\n";
    }
    else
    {
        cout << "----------------------------------\n";
        cout << "          Withdraw Screen          \n";
        cout << "----------------------------------\n";
    }
}

void PrintClientDataString(stClient ClientData)
{
	cout << "| " << setw(20) << left << ClientData.AccountNumber;
	cout << "| " << setw(10) << left << ClientData.PinCode;
	cout << "| " << setw(20) << left << ClientData.Name;
	cout << "| " << setw(15) << left << ClientData.Phone;
	cout << "| " << setw(12) << left << ClientData.AccountBalance;
	cout << "\n";
}

void PrintUserDataString(stUser UserData)
{
	cout << "| " << setw(20) << left << UserData.UserName;
	cout << "| " << setw(10) << left << UserData.Password;
	cout << "| " << setw(20) << left << UserData.Permissions;
	cout << "\n";
}

void PrintBar()
{
	cout << "______________________________________________________________________________________\n\n";
	cout << "| " << setw(20) << left << "Account Number";
	cout << "| " << setw(10) << left << "Pin Code";
	cout << "| " << setw(20) << left << "Client Name";
	cout << "| " << setw(15) << left << "Phone";
	cout << "| " << setw(12) << left << "Balance";
	cout << "\n______________________________________________________________________________________\n";
}

void PrintUserBar()
{
	cout << "______________________________________________________________________________________\n\n";
	cout << "| " << setw(20) << left << "User Name";
	cout << "| " << setw(10) << left << "Password";
	cout << "| " << setw(10) << left << "Permissions";
	cout << "\n______________________________________________________________________________________\n";
}

void PrintClientsData(vector <stClient>& ClientsData)
{
	cout << "\t\t\tClient List ( " << ClientsData.size() << " ) Client(s).\n";
	PrintBar();
	for (stClient client : ClientsData)
	{
		PrintClientDataString(client);
	}
	cout << "______________________________________________________________________________________\n";
}

void PrintUsersData(vector <stUser>& UsersData)
{
	cout << "\t\t\tUser List ( " << UsersData.size() << " ) Client(s).\n";
	PrintUserBar();
	for (stUser User : UsersData)
	{
		PrintUserDataString(User);
	}
	cout << "______________________________________________________________________________________\n";
}

void PrintClientTractionDataString(stClient ClientData)
{
	cout << "| " << setw(20) << left << ClientData.AccountNumber;
	cout << "| " << setw(20) << left << ClientData.Name;
	cout << "| " << setw(12) << left << ClientData.AccountBalance;
	cout << "\n";
}

void PrintTractionBar(string FileName)
{
	cout << "______________________________________________________________________________________\n\n";
	cout << "| " << setw(20) << left << "Account Number";
	cout << "| " << setw(20) << left << "Client Name";
	cout << "| " << setw(12) << left << "Balance";
	cout << "\n______________________________________________________________________________________\n";
}

void PrintClientsTractionData(vector <stClient>& ClientsData)
{
    float TotalBalance = 0;
	cout << "\t\t\tClient List ( " << ClientsData.size() << " ) Client(s).\n";
	PrintTractionBar(FileName);
	for (stClient client : ClientsData)
	{
        TotalBalance += client.AccountBalance;
		PrintClientTractionDataString(client);
	}
	cout << "______________________________________________________________________________________\n";
    cout << "               Total Balances = " << TotalBalance << endl;
}

void AddNewLineToFile(string FileName, string Line)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << Line << endl;
        MyFile.close();
    }
}

void AddNewClientToFile(string FileName, string Client)
{
    AddNewLineToFile(FileName, Client);
}

void AddNewUserToFile(string FileName, string User)
{
    AddNewLineToFile(FileName, User);
}

bool IsFoundClient(string FileName, string AccountToSearch, vector <stClient> vClients)
{
    for (stClient C :vClients)
    {
        if (C.AccountNumber == AccountToSearch)
        {
            return true;
        }        
    }
    return false;
}

bool IsFoundUser(string FileName, string AccountToSearch, vector <stUser> vUsers)
{
    for (stUser User :vUsers)
    {
        if (User.UserName == AccountToSearch)
        {
            return true;
        }        
    }
    return false;
}

string ReadClientUntilAccountNumber(vector <stClient> vClients)
{
    string AccountNumber = "";
    do
    {
        cout << "\nPlease enter AccountNumber: ";
        cin >> AccountNumber;
    }
    while (!(IsFoundClient(FileName, AccountNumber, vClients)));
    return AccountNumber;
}

string ReadClientAccountNumber()
{
    string AccountNumber ="";
    cout << "\nPlease enter AccountNumber: ";
    cin >> AccountNumber;
    return AccountNumber;
}

string ReadUserAccountNumber()
{
    string AccountNumber ="";
    cout << "\nPlease enter User Name: ";
    cin >> AccountNumber;
    return AccountNumber;
}

bool IsClientInFile(string FileName, string AccountToSearchNumber)
{
	stClient ClientData;
	fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {	
        string Client;
        while (getline(MyFile, Client))
        {
            ClientData = ConvertLineToRecord(Client);
            if (ClientData.AccountNumber == AccountToSearchNumber)
            {
                return true;
            }
            
        }
        MyFile.close();
    }
    return false;
}

bool IsUserInFile(string FileName, string AccountToSearchNumber)
{
	stUser UserData;
	fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {	
        string User;
        while (getline(MyFile, User))
        {
            UserData = ConvertLineToRecordUsers(User);
            if (UserData.UserName == AccountToSearchNumber)
            {
                return true;
            }
            
        }
        MyFile.close();
    }
    return false;
}

stClient ReadNewClient()
{
    stClient ClientData;
    do
    {
        ClientData.AccountNumber = ReadText("Enter Account Number: ");
    }while (IsClientInFile(FileName, ClientData.AccountNumber));
    
    ClientData.PinCode = ReadText("Enter PinCode: ");
    ClientData.Name = ReadText("Enter Name: ");
    ClientData.Phone = ReadText("Enter Phone: ");
    ClientData.AccountBalance = ReadPositiveNumber("Account Balance");
    return ClientData;
}

bool ReadBoolAnswer(string massage)
{
    char Answer = 'n';
    cout << massage;
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return 1;
    }
    return 0;
}

short ReadPermissionsToSet()
{
    short Permissions = 0;

    if (ReadBoolAnswer("\nDo you want to give full access y/n: "))
    {
        return -1;
    }

    cout << "\nDo you want to give access to: \n";

    if (ReadBoolAnswer("\nShow Client List? y/n: "))
    {
        Permissions += enMainMenuPermissions::eShowClient;
    }
    if (ReadBoolAnswer("\nAdd New Client? y/n: "))
    {
        Permissions += enMainMenuPermissions::eAddClient;
    }
    if (ReadBoolAnswer("\nDelete Client! y/n: "))
    {
        Permissions += enMainMenuPermissions::eDeleteClient;
    }
    if (ReadBoolAnswer("\nUpdate Client? y/n: "))
    {
        Permissions += enMainMenuPermissions::eUpdateClient;
    }
    if (ReadBoolAnswer("\nFind Client? y/n: "))
    {
        Permissions += enMainMenuPermissions::eFindClient;
    }
    if (ReadBoolAnswer("\nTransactions? y/n: "))
    {
        Permissions += enMainMenuPermissions::eTransactions;
    }
    if (ReadBoolAnswer("\nManage Users? y/n: "))
    {
        Permissions += enMainMenuPermissions::eManageUsers;
    }
    return Permissions;
}

stUser ReadNewUser(bool Update=false)
{
    stUser UserDate;
    if (!Update)
    {
        do      
        {
            UserDate.UserName = ReadText("Enter User Name: ");
        }while (IsUserInFile(UsersFileName, UserDate.UserName));
    }
    UserDate.Password = ReadText("Enter PinCode: ");
    UserDate.Permissions = ReadPermissionsToSet();
    return UserDate;
}

void AddNewClient(string FileName)
{
    AddNewClientToFile(FileName, ConvertRecordToLine(ReadNewClient(), "#//#"));
}

void AddNewUser(string FileName)
{
    AddNewUserToFile(FileName, ConvertRecordToLineUsers(ReadNewUser(), "#//#"));
}

void AddNewClientsToFile(string FileName)
{
    string Continue = "y";
    do
    {
        system("cls");
        cout << "Adding new client: \n";
        AddNewClient(FileName);
        Continue = ReadChar("Client Added Successfully: do you want to add more clients[y/n]: ");
        
    } while (Continue == "Y" || Continue == "y");
}

void AddNewUsersToFile(string FileName)
{
    string Continue = "y";
    do
    {
        system("cls");
        cout << "Adding new User: \n";
        AddNewUser(FileName);
        Continue = ReadChar("User Added Successfully: do you want to add more Users?[y/n]: ");
        
    } while (Continue == "Y" || Continue == "y");
}

bool DeleteOrNot()
{
	string DeleteOrNo;
	cout << "Are you sure you want delete this Account (1/0): ";
	cin >> DeleteOrNo;
	if (DeleteOrNo == "Y" || DeleteOrNo == "y" || DeleteOrNo == "1")
	{
		return true;
	}
	return false;
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

vector <stClient> CreateNewVectorAndDelete(string FileName, string AccountToSearch)
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
            if (!(ClientData.AccountNumber == AccountToSearch))
            {	
                vClient.push_back(ClientData);
            }
            else
            {
                PrintClient(ClientData);
                if (!DeleteOrNot())
                {
                    vClient.push_back(ClientData);
                }
                else
                    cout << "Client Deleted successfully";
            }
        }
    	MyFile.close();
    }
	return vClient;
}

vector <stUser> CreateNewVectorAndDeleteUser(string FileName, string AccountToSearch)
{
	stUser UserData;
	fstream MyFile;
	vector <stUser> vUser;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
		string User;
        while (getline(MyFile, User))
        {
            UserData = ConvertLineToRecordUsers(User);
            if (!(UserData.UserName == AccountToSearch))
            {	
                vUser.push_back(UserData);
            }
            else
            {
                PrintUser(UserData);
                if (!DeleteOrNot())
                {
                    vUser.push_back(UserData);
                }
                else
                    cout << "User Deleted successfully";
            }
        }
    	MyFile.close();
    }
	return vUser;
}

void DeleteClientFromFile(string FileName, string AccountToSearch)
{
	vector <stClient> NewClient = CreateNewVectorAndDelete(FileName, AccountToSearch);
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

void DeleteUserFromFile(string FileName, string AccountToSearch)
{
	vector <stUser> NewUsers = CreateNewVectorAndDeleteUser(FileName, AccountToSearch);
	fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
		for (stUser & C : NewUsers)
		{
			MyFile << ConvertRecordToLineUsers(C) << "\n";
		}
	}
}

void PrintClientByAccountNumber(string AccountToSearch, vector <stClient> vClients)
{   
    if (IsFoundClient(FileName, AccountToSearch, vClients))
    {
        for (stClient C :vClients)
        {
            if (C.AccountNumber == AccountToSearch)
            {
                PrintClient(C);
            }
        }
    }
    else
        cout << "Client Wasn't found!.";     
}

void PrintUserByAccountNumber(string AccountToSearch, vector <stUser> vUsers)
{   
    if (IsFoundUser(UsersFileName, AccountToSearch, vUsers))
    {
        for (stUser User :vUsers)
        {
            if (User.UserName == AccountToSearch)
            {
                PrintUser(User);
            }
        }
    }
    else
        cout << "User Wasn't found!.";     
}

vector <stClient> CreateNewUpdatedVector(string FileName, string AccountToSearch)
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
			if (!(ClientData.AccountNumber == AccountToSearch))
			{	
				vClient.push_back(ClientData);
			}
			else
			{
				PrintClient(ClientData);
				if (UpdateOrNot())
				{
					stClient UpdatedClient = ReadNewClient();
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

vector <stUser> CreateNewUpdatedVectorUser(string FileName, string AccountToSearch)
{
	stUser UserData;
	fstream MyFile;
	vector <stUser> vUser;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {	
		string User;
		while (getline(MyFile, User))
		{
			UserData = ConvertLineToRecordUsers(User);
			if (!(UserData.UserName == AccountToSearch))
			{	
				vUser.push_back(UserData);
			}
			else
			{
				PrintUser(UserData);
				if (UpdateOrNot())
				{
					stUser UpdatedUser = ReadNewUser(true);
					UpdatedUser.UserName = AccountToSearch;
					vUser.push_back(UpdatedUser);
					cout << "User Updated successfully";
				}
			}
		}
    	MyFile.close();
    }
	return vUser;
}

void UploadClientsForFile(vector <stClient> vClients)
{
	fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
            MyFile << ConvertRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}

float ReadDepositBalance()
{
    float DepositAmount = 0;
    do
    {
        cout << "Please enter deposit amount: ";
        cin >> DepositAmount;
    } while (DepositAmount < 0);
    return DepositAmount;
}

float ReadWithdrawBalance(float balance)
{
    float WithdrawAmount = 0;
    do
    {
        cout << "Please enter Withdraw amount: ";
        cin >> WithdrawAmount;
    } while (balance <= WithdrawAmount);
    return WithdrawAmount;
}

void UpdateClientFromFile(string FileName, string AccountToSearch)
{
	vector <stClient> NewClient = CreateNewUpdatedVector(FileName, AccountToSearch);
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

void UpdateUserFromFile(string FileName, string AccountToSearch)
{
	vector <stUser> NewUser = CreateNewUpdatedVectorUser(FileName, AccountToSearch);
	fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
		for (stUser & User : NewUser)
		{
			MyFile << ConvertRecordToLineUsers(User) << "\n";
		}
	}
}

void DepositAndWithdrawBalance(string AccountToSearch,vector <stClient> &vClients,bool Deposit)
{
    for (stClient& C :vClients)
    {
        if (C.AccountNumber == AccountToSearch)
        {
            if (Deposit)
            {   
                C.AccountBalance += ReadDepositBalance();
            }   
            else
            {
                C.AccountBalance -= ReadWithdrawBalance(C.AccountBalance);
            }
        }
    }
}

void DepositAndWithdrawScreen(bool Deposit=true)
{
    PrintDepositAndWithdrawScreen(Deposit);
    vector <stClient> vClients = LoadClientsDataFromFile(FileName);
    string AccountToSearch = ReadClientUntilAccountNumber(vClients);
    PrintClientByAccountNumber(AccountToSearch, vClients);
    DepositAndWithdrawBalance(AccountToSearch, vClients, Deposit);
    UploadClientsForFile(vClients);
    ResetScreenTransactionsMenu();
}

bool FindUserByUserNameAndPassword(string UserName, string Password, stUser& User)
{
    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    for (stUser U : vUsers)
    {
        if (U.UserName == UserName && U.Password == Password)
        {
            User = U;
            return true;
        }
    }
    return false;
}

bool LoadUserInfo(string UserName, string Password)
{
    if (FindUserByUserNameAndPassword(UserName, Password, CurrentUser))
        return true;
    return false;
}

void ScreenShowClient()
{
    system("cls");
    vector <stClient> vClients = LoadClientsDataFromFile(FileName);
    PrintClientsData(vClients);
    ResetScreenMenu();
}

void ScreenShowClientTraction()
{
    system("cls");
    vector <stClient> vClients = LoadClientsDataFromFile(FileName);
    PrintClientsTractionData(vClients);
    ResetScreenTransactionsMenu();
}

void ScreenAddClient()
{
    system("cls");
    AddNewClientsToFile(FileName);
    ResetScreenMenu();
}

void ScreenDeleteClient()
{
    system("cls");
    string AccountToSearch = ReadClientAccountNumber();
    DeleteClientFromFile(FileName, AccountToSearch);
    ResetScreenMenu();
}

void ScreenUpdateClient()
{
    system("cls");
    string AccountToSearch = ReadClientAccountNumber();
    UpdateClientFromFile(FileName, AccountToSearch);
    ResetScreenMenu();
}

void ScreenFindClient()
{
    system("cls");
    vector <stClient> vClients = LoadClientsDataFromFile(FileName);
    string AccountToSearch = ReadClientAccountNumber();
    PrintClientByAccountNumber(AccountToSearch, vClients);
    ResetScreenMenu();
}

void ScreenTransactions()
{
    system("cls");
    StartTransactionsScreenMenu();
}

void ScreenManageUsers()
{
    system("cls");
    StartUserManageScreenMenu();
}

void ScreenShowUser()
{
    system("cls");
    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    PrintUsersData(vUsers);
    ResetScreenUserMenu();
}

void ScreenAddUser()
{
    system("cls");
    AddNewUsersToFile(UsersFileName);
    ResetScreenUserMenu();
}

void ScreenDeleteUser()
{
    system("cls");
    string UserToSearch = ReadUserAccountNumber();
    DeleteUserFromFile(UsersFileName, UserToSearch);
    ResetScreenUserMenu();
}

void ScreenUpdateUser()
{
    system("cls");
    string UserToSearch = ReadUserAccountNumber();
    UpdateUserFromFile(UsersFileName, UserToSearch);
    ResetScreenUserMenu();
}

void ScreenFindUser()
{
    system("cls");
    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    string UserToSearch = ReadUserAccountNumber();
    PrintUserByAccountNumber(UserToSearch, vUsers);
    ResetScreenUserMenu();
}

void LogoutProgram()
{
    system("cls");
    Login();
}

void MyTChoice(enTMenu MenuChoice)
{
    switch (MenuChoice)
    {
    case enTMenu::Deposit:
        DepositAndWithdrawScreen(true);
        break;
    case enTMenu::Withdraw:
        DepositAndWithdrawScreen(false);
        break;
    case enTMenu::TotalBalance:
        ScreenShowClientTraction();
        break;
    case enTMenu::MainMenu:
        system("cls");
        StartScreenMenu();
        break;
    default:
        break;
    }
}

bool CheckAccessPermission(enMainMenuPermissions Permission)
{
    if (CurrentUser.Permissions == enMainMenuPermissions::eAll)
        return true;
    if ((Permission & CurrentUser.Permissions) == Permission)
        return true;
    else
        return false;
    
}

void ShowAccessDeniedMessage()
{
    system("cls");
    cout << "\n-------------------------------\n";
    cout << "Access Denied, \nYou don't have Permission to do this,\nPlease contact with your Admin.\n";
    cout << "-------------------------------\n";
}

void MyChoice(enMenu MenuChoice)
{
    switch (MenuChoice)
    {
    case enMenu::ShowClient:
        if (!CheckAccessPermission(enMainMenuPermissions::eShowClient))
        {
            ShowAccessDeniedMessage();
            ResetScreenMenu();
        }
        ScreenShowClient();
        break;
    case enMenu::AddClient:
        if (!CheckAccessPermission(enMainMenuPermissions::eAddClient))
        {
            ShowAccessDeniedMessage();
            ResetScreenMenu();
        }
        ScreenAddClient();
        break;
    case enMenu::DeleteClient:
        if (!CheckAccessPermission(enMainMenuPermissions::eDeleteClient))
        {
            ShowAccessDeniedMessage();
            ResetScreenMenu();
        }
        ScreenDeleteClient();
        break;
    case enMenu::UpdateClient:
        if (!CheckAccessPermission(enMainMenuPermissions::eUpdateClient))
        {
            ShowAccessDeniedMessage();
            ResetScreenMenu();
        }
        ScreenUpdateClient();
        break;
    case enMenu::FindClient:
        if (!CheckAccessPermission(enMainMenuPermissions::eFindClient))
        {
            ShowAccessDeniedMessage();
            ResetScreenMenu();
        }
        ScreenFindClient();
        break;
    case enMenu::Transactions:
        if (!CheckAccessPermission(enMainMenuPermissions::eTransactions))
        {
            ShowAccessDeniedMessage();
            ResetScreenMenu();
        }
        ScreenTransactions();
        break;
    case enMenu::ManageUsers:
        if (!CheckAccessPermission(enMainMenuPermissions::eManageUsers))
        {
            ShowAccessDeniedMessage();
            ResetScreenMenu();
        }
        ScreenManageUsers();
        break;
    case enMenu::Logout:
        LogoutProgram();
        break;
    default:
        break;
    }
}

void MyUChoice(enManageUserMenu MenuChoice)
{
    switch (MenuChoice)
    {
    case enManageUserMenu::ShowUser:
        ScreenShowUser();
        break;
    case enManageUserMenu::AddUser:
        ScreenAddUser();
        break;
    case enManageUserMenu::DeleteUser:
        ScreenDeleteUser();
        break;
    case enManageUserMenu::UpdateUser:
        ScreenUpdateUser();
        break;
    case enManageUserMenu::FindUser:
        ScreenFindUser();
        break;
    case enManageUserMenu::BackMain:
        StartScreenMenu();
        break;
    default:
        break;
    }
}

enTMenu ChoiceTransactionsMenuScreen()
{
    short number = 0;
    cout << "=============================================================\n";
    cout << "             Transactions Main Menu Screen                   \n";
    cout << "=============================================================\n";
    cout << left << setw(37) << "[1]Deposit." << endl;
    cout << left << setw(37) << "[2]Withdraw." << endl;
    cout << left << setw(37) << "[3]Total Balance." << endl;
    cout << left << setw(37) << "[4]Main Menu." << endl;
    cout << "Choose what do you want to do: [1 to 4]: ";
    cin >> number;
    return enTMenu(number);
}

enManageUserMenu ChoiceManageUserMenuScreen()
{
    
    system("cls");
    cout << "=============================================================\n";
    cout << "                  Manage User Screen                   \n";
    cout << "=============================================================\n";
    cout << left << setw(37) << "[1]List Users." << endl;
    cout << left << setw(37) << "[2]Add New User." << endl;
    cout << left << setw(37) << "[3]Delete User." << endl;
    cout << left << setw(37) << "[4]Update User." << endl;
    cout << left << setw(37) << "[5]Find User." << endl;
    cout << left << setw(37) << "[6]Main Menu." << endl;
    short number = 0;
    cout << "Choose what do you want to do: [1 to 6]: ";
    cin >> number;
    return enManageUserMenu(number);
}

enMenu ScreenMenuChoice()
{
    system("cls");
    short number = 0;
    cout << "=============================================================\n";
    cout << "                  Main Menu Screen                           \n";
    cout << "=============================================================\n";
    cout << left << setw(37) << "[1]Show Client Lest." << endl;
    cout << left << setw(37) << "[2]Add New Client." << endl;
    cout << left << setw(37) << "[3]Delete Client." << endl;
    cout << left << setw(37) << "[4]Update Client." << endl;
    cout << left << setw(37) << "[5]Find Client." << endl;
    cout << left << setw(37) << "[6]Transactions." << endl;
    cout << left << setw(37) << "[7]Manage Useres." << endl;
    cout << left << setw(37) << "[8]Logout." << endl;
    cout << "Choose what do you want to do: [1 to 8]: ";
    cin >> number;
    return enMenu(number);
}

void StartScreenMenu()
{
    MyChoice(ScreenMenuChoice());
}

void StartTransactionsScreenMenu()
{
    MyTChoice(ChoiceTransactionsMenuScreen());
}

void StartUserManageScreenMenu()
{
    MyUChoice(ChoiceManageUserMenuScreen());
}

void Login()
{
    bool LoginFeild = false;
    string UserName, Password;
    do
    {
        system("cls");
        cout << "\n--------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n--------------------------\n";
        if (LoginFeild)
        {
            cout << "Invalid Username/Password!\n";
        }
        cout << "Enter Username: ";
        cin >> UserName;

        cout << "Enter Password: ";
        cin >> Password;
        LoginFeild = !LoadUserInfo(UserName, Password);
    } while (LoginFeild);
    StartScreenMenu();
}

int main()
{
    Login();
    system("pause>0");
	return 0;
}
