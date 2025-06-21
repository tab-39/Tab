#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enChoice {Stone = 1, Paper = 2, Scissors = 3};
enum enWinner {Player1 = 1, Computer = 2, Draw = 3};

string ChoicePSS(enChoice Choice)
{
    string ChoiceString[3] = {"Stone", "Paper", "Scissors"}; 
    return ChoiceString[Choice - 1];
}

string WinnerS(enWinner winner)
{
    string WinnerString[3] = {"Player1", "Computer", "Draw"};
    return WinnerString[winner - 1];
}

struct stRoundInfo
{
    short RoundNumber = 0;
    enChoice Player1Choice, ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

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

enChoice PlayerChoice()
{
    int Choice = ReadPositiveFromToNumber("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors: ", 1, 3);
    return enChoice(Choice);
}

enChoice BotChoice()
{
    return enChoice(RandomNumber(1, 3));
}

enWinner CheckRoundWinner(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return Draw;
    }
    else if (RoundInfo.Player1Choice == Paper && RoundInfo.ComputerChoice == Stone)
    {
        return Player1;
    }
    else if (RoundInfo.Player1Choice == Stone && RoundInfo.ComputerChoice == Scissors)
    {
        return Player1;
    }
    else if (RoundInfo.Player1Choice == Scissors && RoundInfo.ComputerChoice == Paper)
    {
        return Player1;
    }
    else
        return Computer;
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case Player1:
        system("color 2F");
        break;
    case Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");
        break;
    }
}

enWinner CheckRoundsWinner(stGameResults GameResults)
{
    if (GameResults.Player1WinTimes > GameResults.ComputerWinTimes)
        return Player1;
    else if (GameResults.ComputerWinTimes > GameResults.Player1WinTimes)
        return Computer;
    return Draw;
}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 0; i < NumberOfTabs; i++)
    {
        t += "\t";
    }
    return t;
}

void PrintRoundWinner(stRoundInfo RoundInfo)
{
    SetWinnerScreenColor(RoundInfo.Winner);
    cout << "\n______________Round [" << RoundInfo.RoundNumber << "]______________\n";
    cout << "Player1  Choice: " << ChoicePSS(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoicePSS(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : " << RoundInfo.WinnerName << endl;
    cout << "_____________________________________\n\n";
}

void PrintGameOver()
{    
    cout << Tabs(4) << "______________________________________________________\n\n";
    cout << Tabs(4) << "               +++ G a m e  O v e r +++               \n";
    cout << Tabs(4) << "______________________________________________________\n\n";
}

void PrintRoundsWinner(stGameResults GameResults)
{
    SetWinnerScreenColor(GameResults.GameWinner);
    cout << Tabs(4) << "____________________[Game Results]____________________\n\n";
    cout << Tabs(4) << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << Tabs(4) << "Player 1 won times : " << GameResults.Player1WinTimes << endl;
    cout << Tabs(4) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(4) << "Draw times         : " << GameResults.DrawTimes << endl;
    cout << Tabs(4) << "Final Winner       : " << GameResults.WinnerName << endl;
    cout << Tabs(4) << "______________________________________________________\n\n"; 
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

stGameResults FillGameResults(short Rounds, short playerWins, short ComputerWins, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = Rounds;
    GameResults.Player1WinTimes = playerWins;
    GameResults.ComputerWinTimes = ComputerWins;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = CheckRoundsWinner(GameResults);
    GameResults.WinnerName = WinnerS(GameResults.GameWinner);
    return GameResults;
}

stGameResults PlayGame(short Rounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRounds = 1; GameRounds <= Rounds; GameRounds++)
    {
        cout << "Round [" << GameRounds << "] begins: \n\n";
        RoundInfo.Player1Choice = PlayerChoice();
        RoundInfo.ComputerChoice = BotChoice();
        RoundInfo.RoundNumber = GameRounds;
        RoundInfo.Winner = CheckRoundWinner(RoundInfo);
        RoundInfo.WinnerName = WinnerS(RoundInfo.Winner);
        if (RoundInfo.Winner == Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;
        PrintRoundWinner(RoundInfo);
    }
    return FillGameResults(Rounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

void StartGame()
{   
    string ContinueOrNot;
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadPositiveFromToNumber("How Many Rounds 1 to 10: ", 1, 10));
        PrintGameOver();
        PrintRoundsWinner(GameResults);
        cout << Tabs(4) << "Do you Want to play again? Y/N: ", cin >> ContinueOrNot;
    } while (ContinueOrNot == "y" || ContinueOrNot == "Y");
    
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
};
