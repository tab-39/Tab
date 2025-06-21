#pragma once
#include <iostream>
#include <vector>
#include "InputLib.h"
using namespace std;

class clsString
{
    private:
    string _Value;

    public:
    clsString()
    {
        _Value = "";
    }
    clsString(string Value)
    {
        _Value = Value;
    }
    void SetValue(string Value)
    {
        _Value = Value;
    }
    string Value()
    {
        return _Value;
    }
    static void FirstLetterInString(string text)
    {
        string name = InputLib::ReadText("What is Your name: ");
	bool isFirstLetter = true;
	for (char letter : text)
    {
		if (letter != ' ' && isFirstLetter)
		{
			cout << letter << endl;
		}
		isFirstLetter = (letter == ' ')? true : false;
	}
    }
    void FirstLetterInString()
    {
        FirstLetterInString(_Value);
    }   
    static void title(string& text)
    {
        bool isFirstLetter = true;
        for (char & letter : text)
        {
            if (letter != ' ' && isFirstLetter)
            {
                if (letter < 123 && letter > 96)
                {
                    letter -= 32;
                }
            }
            isFirstLetter = (letter == ' ')? true : false;
        }
    }
    void title()
    {
        title(_Value);
    }
    static void titleLower(string& text)
    {
        bool isFirstLetter = true;
        for (char & letter : text)
        {
            if (letter != ' ' && isFirstLetter)
            {
                if (letter < 91 && letter > 64)
                {
                    letter += 32;
                }
            }
            isFirstLetter = (letter == ' ')? true : false;
        }
    }
    void titleLower()
    {
        titleLower(_Value);
    }
    static void Upper(string& text)
    {
        for (char & letter : text)
        {
            if (letter != ' ')
            {
                if (letter < 123 && letter > 96)
                {
                    letter -= 32;
                }
            }
        }
    }
    void Upper()
    {
        Upper(_Value);
    }
    static void Lower(string& text)
    {
        for (char & letter : text)
        {
            if (letter != ' ')
            {
                if (letter < 91 && letter > 64)
                {
                    letter += 32;
                }
            }
        }
    }
    void Lower()
    {
        Lower(_Value);
    }
    static int CountLetter(string& text, char count, bool MatchCase=true)
    {
        int counter = 0;
        for (char & character : text)
        {
            if (MatchCase)
            {
                if (character == count)
                {
                    counter++;
                }
            }
            else
                if (tolower(character) == tolower(count))
                {
                    counter++;
                }
            
        }
        return counter;
    }
    int CountLetter(char count, bool MatchCase=true)
    {
        return CountLetter(_Value, count);
    }
    static bool IsVowel(char character)
    {
        return (tolower(character) == 'a' || tolower(character) == 'e' || tolower(character) == 'i' || tolower(character) == 'o' || tolower(character) == 'u');
    }

    static int CountVowel(string text)
    {
        int counter = 0;
        for (char& letter : text)
        {
            if (IsVowel(letter))
            {
                counter ++;
            }
        }
        return counter;
    }
    int CountVowel()
    {
        return CountVowel(_Value);
    }
    static void PrintVowel(string text)
    {
        for (char& letter : text)
        {
            if (IsVowel(letter))
                cout << letter << "   ";
        }
    }
    void PrintVowel()
    {
        PrintVowel(_Value);
    }
    static void PrintWords(string text)
    {
        string delim = " ";
        cout << "\nYour string words are: \n\n";
        short pos = 0;
        string sWord = "";

        while ((pos = text.find(delim)) != std::string::npos)
        {
            sWord = text.substr(0, pos);
            if (sWord != "")
            {
                cout << sWord << endl;
            }
            text.erase(0, pos+delim.length());
        }
        if (text != "")
        {
            cout << text << endl;
        }
        
    }
    void PrintWords()
    {
        PrintWords(_Value);
    }
    static int CountWords(string text)
    {
        int counter = 0;
        string delim = " ";
        short pos = 0;
        string sWord = "";

        while ((pos = text.find(delim)) != std::string::npos)
        {
            sWord = text.substr(0, pos);
            if (sWord != "")
            {
                counter++;
            }
            text.erase(0, pos+delim.length());
        }
        if (text != "")
        {
            counter++;
        }
        return counter;
    }
    int CountWords()
    {
        return CountWords(_Value);
    }

    




};
