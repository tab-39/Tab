#pragma once
#include<iostream>
#include<fstream>
#include "MathLib.h"
#include <cmath>

using namespace std;

namespace InputLib
{

    float ReadNumber(string typeOfNumber)
    {
        float N;
        cout << "Please enter "<< typeOfNumber <<" : ", cin >> N;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid number: ", cin >> N;
        }
        
        return N;
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
    void printInvertedPattern(int number)
    {
        for (int i = number; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << "\n";
        }
        
    }
    void printInvertedLetterPattern(int number)
    {
        for (int i = number; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << char(i+64);
            }
            cout << "\n";
        }
        
    }
    string ReadText(string massage)
    {
        string text;
        cout << massage;
        getline(cin >> ws, text);
        return text;
    }
    void ReadArray(int Element[100], int elementCounter)
    {
        for (int i = 0; i < elementCounter; i++)
        {
            cout << "Element [" << i+1 << "]: ";
            cin >> Element[i];
        }
    }
    void PrintArray(int ArrayN[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            cout << ArrayN[i] << " ";
        }
        cout << endl;
    }
    bool CheckContinue()
    {
        bool Check;

        cout << "Do you want to Continue ? [0]:No, [1]:yes: ", cin >> Check;
        cout << endl;
        return Check;
    }
    char ReadChar(string massage)
    {
        char character;
        cout << massage, cin >> character;
        return character;
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
}
