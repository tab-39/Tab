#pragma once
#include<iostream>
#include <cmath>
#include "D:/projects/C++_projects/MyLibrarys/MyLib.h"
#include "D:/projects/C++_projects/MyLibrarys/InputLib.h"
using namespace std;

enum enChar {SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};

namespace MathLib
{
    int Sum2Numbers(int a, int b)
    { 
        return a + b;
    } 
    bool IsPerfect(int number)
    {
        int sumN = 0;
        for (int i = 1; i <= (number/2); i++)
        {
            if (number % i == 0)
                sumN += i;
        }
        if (sumN == number)
        {
            return true;
        }
        else 
            return false;
    }
    int ReversNumber(int Number)
    {
        float ReversedNumber, remainder;
        while (Number > 0)
        {
            remainder = Number % 10;
            Number /=10;
            ReversedNumber *= 10;
            ReversedNumber += remainder;
        }
        return ReversedNumber;
    }
    int FrequencyOfNumber(int Digits, int Digit)
    {
        int Frequency = 0, Remainder;
        while (Digits > 0)
        {
            Remainder = Digits % 10;
            if (Remainder == Digit)
                Frequency++;
            Digits /= 10;
        }
        
        return Frequency;
    }
    bool CheckPalindrome(int number)
    {
        return number == ReversNumber(number);
    }
    int RandomNumber(int from, int to)
    {
        int RandNumber = rand() % (to - from + 1) + from;
        return RandNumber;
    }
    char RandomChar(enChar CharType)
    {
        char Char;
        switch (CharType)
        {
        case enChar::SmallLetter:
            Char = RandomNumber(97, 122);
            return Char;
        case enChar::CapitalLetter:
            Char = RandomNumber(65, 91);
            return Char;
        case enChar::SpecialCharacter:
            Char = RandomNumber(33, 47);
            return Char;
        case enChar::Digit:
            Char = RandomNumber(48, 57);
            return Char;
        }
        return 0;
    }
    string GenerateWord(enChar TypeChar, int length)
    {
        string Key;
            for (int j = 1; j <= length; j++)
        {
            Key += RandomChar(TypeChar);
        }
        return Key;
    }
    string GenerateKey()
    {
        string key;
        for (int i = 1; i <= 4; i++)
        {
            key += GenerateWord(CapitalLetter, 4);
            if (i < 4)
                key += "-";
        }
        
        return key;
    }
    void FillArrayByKeys(string arr[100], int counter)
{
    for (int i = 0; i < counter; i++)
    {
        arr[i] = GenerateKey();
    }
    
}
    void RandomArray(int arr[100], int elementCounter)
    {
        for (int i = 0; i < elementCounter; i++)
        {
            arr[i] = RandomNumber(1, 100);
        }    
    }
    int Max(int arr[100], int length)
    {
        int maxNumber = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (maxNumber < arr[i])
                maxNumber = arr[i];
        }
        return maxNumber;
    }
    int MIN(int arr[100], int length)
    {
        int maxNumber = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (maxNumber > arr[i])
                maxNumber = arr[i];
        }
        return maxNumber;
    }
    int SUM(int arr[100], int length)
    {
        int SumNumber;
        for (int i = 0; i < length; i++)
        {
            SumNumber += arr[i];
        }
        return SumNumber;
    }
    float Average(int arr[100], int length)
    {
        float Average = SUM(arr, length) / length;
        return Average;
    }
    void ToNArray(int arr[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            arr[i] = i+1;
        }
    }
    void ShuffleArray(int arr[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            swap(arr[RandomNumber(1, length)-1], arr[RandomNumber(1, length)-1]);
        }
    }
    int CountOddArray(int arr[100], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] % 2 != 0)
                counter++;
            
        }
        return counter;
    }
    int CountEvenArray(int arr[100], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] % 2 == 0)
                counter++;
            
        }
        return counter;
    }
    int CountPositiveArray(int arr[100], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] > 0)
                counter++;
            
        }
        return counter;
    }
    int CountNegativeArray(int arr[100], int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] < 0)
                counter++;
            
        }
        return counter;
    }
    float MyAbs(float number)
    {
        if (number < 0)
            return -number;

        return number;
    }
    int GetFractionPart(float number)
    {
        return 10*(number - int(number));
    }
    int MyRound(float number)
    {

        int fraction = GetFractionPart(number);

        if (number > 0)
        {
            if (fraction > 4)
                return number+1;
        }
        else
        {
            if (-fraction > 4)
                return number-1;
        }

        return number;
    }
    int MyFloor(float number)
    {
        if (number < 0 && number < int(number))
            return number-1;
        return number;
    }
    int MyCeil(float number)
    {
        if (number > 0 && number > int(number))
            return number+1;

        return number;
    }
    float MySqrt(int number)
    {
        return pow(number, 0.5);
    }
}
