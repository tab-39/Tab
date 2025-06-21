#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"



using namespace std;
struct stClientData
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

namespace MyLib
{

    int FindIndex(int arr[100], int object, int length)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == object)
            {
                return i;
            }
        }
        return -1;
    }
    string Encryption(string text)
    {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = char(text[i] + 2);
            
        }
        return text;
    }
    string Decryption(string text)
    {
        string Encrypted = "";
        for (int i = 0; i < text.length(); i++)
        {
            char letter = text[i] - 2;
            Encrypted += letter;
        }
        return Encrypted;
    }
    void CopyArray(int arr[100], int CopedArray[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            CopedArray[i] = arr[i];
        }
    }
    void Swap(int& A, int& B)
    { 
        int Temp = A;
        A = B;
        B = Temp;
    }
    void CopyAndReveresArray(int arr[100], int CopedArray[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            CopedArray[length-i-1] = arr[i];
        }
    }
    void Append(int Number, int arr[100], int& arrLength)
    {
        arr[arrLength] = Number;
        arrLength++;
    }
    char ChangeCase(char character)
    {
        if (character != ' ')
        {
            if (character < 123 && character > 96)
            {
                return character - 32;
            }
            else if (character < 91 && character > 64)
            {
                return character + 32;
            }
        }
        return character;
    }
    void ChangeStringCase(string& text)
    {
        for (char& character : text)
        {
            ChangeCase(character);
        }
        
    }
    vector<string> SplitL(string text, string delim = " ")
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
    void AddNewClientToFile(string FileName, string Client)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << Client << endl;
            MyFile.close();
        }
    }
    void AddNewClient(string FileName)
    {
        AddNewClientToFile(FileName, ConvertRecordToLine(ReadNewClient(), "#//#"));
    }
    void AddNewClientsToFile(string FileName)
    {
        string Continue = "y";
        do
        {
            system("cls");
            cout << "Adding new client: \n";
            AddNewClient(FileName);
            Continue = InputLib::ReadChar("Client Added Successfully: do you want to add more clients[y/n]: ");
            
        } while (Continue == "Y" || Continue == "y");
        
    }
}
