#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enOperation{Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};
enum enLevel{Easy = 1, Med = 2, Hard = 3, MixL = 4};
enum enPassOrFail{Pass = true, Fail = false};

struct stRoundInfo
{
    short FirstNumber, SecondNumber, Answer, UserAnswer, CorrectAnswer=0, WrongAnswer=0, Rounds=0;
    enOperation Operation;
    string StringOperation;
    enLevel Level;
    enPassOrFail PassOrFail;
};

string stringLevel(enLevel Level)
{
    string Levels[4] = {"Easy", "Med", "Hard", "MixL"};
    return Levels[Level-1];
}

string stringOperation(enOperation Operation)
{
    string Operations[5] = {"Add", "Sub", "Mul", "Div", "MixOp"};
    return Operations[Operation-1];
}

string StringPassOrFail(bool Pass)
{
    if (Pass)
        return "PASS :-)";
    return "FAIL :-(";
}

int ReadPositiveFromToNumber(string massage, int from, int to)
{
    int N;
    do
    {
        cout << massage, cin >> N;
    }while (!(N >= from && N <= to));
    return N;
}

int RandomNumber(int from, int to)
{
    int RandNumber = rand() % (to - from + 1) + from;
    return RandNumber;
}

int RandomNumberByLevel(enLevel Level)
{
    if (Level == MixL)
        return RandomNumber(1, 100);
    switch (Level)
    {
    case Easy:
        return RandomNumber(1, 10);
    case Med:
        return RandomNumber(10, 50);
    case Hard:
        return RandomNumber(50, 100);
    }
    return 0;
}

int Calculate(stRoundInfo& RoundInfo)
{
    short FirstNumber = RoundInfo.FirstNumber;
    short SecondNumber = RoundInfo.SecondNumber;
    enOperation Operation =  RoundInfo.Operation;

    if (Operation == MixOp)
    {
        Operation = (enOperation)RandomNumber(1, 4);
    }

    switch (Operation)
    {
    case Add:
        RoundInfo.StringOperation = "+";
        return FirstNumber + SecondNumber;
    
    case Sub:
        RoundInfo.StringOperation = "-";
        return FirstNumber - SecondNumber;
    
    case Mul:
        RoundInfo.StringOperation = "*";
        return FirstNumber * SecondNumber;
    
    case Div:
        RoundInfo.StringOperation = "/";
        return FirstNumber / SecondNumber;
    }
    return 0;
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void SetScreenColor(bool Correct)
{
    switch (Correct)
    {
    case true:
        system("color 2F");
        break;
    case false:
        system("color 4F");
        cout << "\a";
        break;
    }
}

bool CheckCorrectAnswer(stRoundInfo& RoundInfo)
{
    if (RoundInfo.UserAnswer == RoundInfo.Answer)
        {
        RoundInfo.CorrectAnswer++;
        return true;
        }
    RoundInfo.WrongAnswer++;
    return false;
}

void PrintAnswer(bool CorrectOrNot, short Answer)
{
    SetScreenColor(CorrectOrNot);
    if (CorrectOrNot)
        cout << "Right Answer :-)";
        
    else
        cout << "Wrong Answer :-(\nThe right answer is: " << Answer;
}

void PassOrFailGame(stRoundInfo RoundInfo)
{
    if (RoundInfo.CorrectAnswer > RoundInfo.WrongAnswer)
        RoundInfo.PassOrFail = Pass;
    RoundInfo.PassOrFail = Fail;
}

void PrintFinalGame(stRoundInfo RoundInfo)
{
    SetScreenColor(RoundInfo.PassOrFail);
    cout << "\n_________________________________\n\n";
    cout << "Final Result is " << StringPassOrFail(RoundInfo.PassOrFail);
    cout << "\n_________________________________";
    cout << "\nNumber Of Questions: " << RoundInfo.Rounds;
    cout << "\nQuestions Level    : " << stringLevel(RoundInfo.Level);
    cout << "\nOperation Type     : " << stringOperation(RoundInfo.Operation);
    cout << "\nNumber Of Right Answer:" << RoundInfo.CorrectAnswer;
    cout << "\nNumber Of Wrong Answer:" << RoundInfo.WrongAnswer;
    cout << "\n_________________________________\n";
}

void AskAndCorrectQuestions(stRoundInfo& RoundInfo)
{
    for (int GameRound = 1; GameRound <= RoundInfo.Rounds; GameRound++)
    {
        RoundInfo.FirstNumber = RandomNumberByLevel(RoundInfo.Level);
        RoundInfo.SecondNumber = RandomNumberByLevel(RoundInfo.Level);
        RoundInfo.Answer = Calculate(RoundInfo);
        cout << "\nQuestion[" << GameRound << "/"<< RoundInfo.Rounds << "]\n\n";
        cout << RoundInfo.FirstNumber << "\n" << RoundInfo.SecondNumber << " " << RoundInfo.StringOperation << "\n_______\n";
        cin >> RoundInfo.UserAnswer;
        PrintAnswer(CheckCorrectAnswer(RoundInfo), RoundInfo.Answer);
    }
}

void PlayGame()
{
    stRoundInfo RoundInfo;
    RoundInfo.Rounds = ReadPositiveFromToNumber("How Many Questions do You want to answer: ", 1, 100);
    RoundInfo.Level = (enLevel)ReadPositiveFromToNumber("Enter Questions Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix: ", 1, 4);
    RoundInfo.Operation = (enOperation)ReadPositiveFromToNumber("Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix: ", 1, 5);
    AskAndCorrectQuestions(RoundInfo);
    PassOrFailGame(RoundInfo);
    PrintFinalGame(RoundInfo);
}

void StartGame()
{   
    string ContinueOrNot;
    short Rounds;
    do
    {
        ResetScreen();
        PlayGame();
        cout << "Do you Want to play again? Y/N: ", cin >> ContinueOrNot;
    } while (ContinueOrNot == "y" || ContinueOrNot == "Y");
    
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
};