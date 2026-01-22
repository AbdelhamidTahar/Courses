#include <iostream>
using namespace std;

enum enGameChoice {Stone = 1, Paper = 2, Scissor = 3};

enum enWinner {Player1 = 1 , Computer = 2 , Draw = 3};

struct strRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = "";

};

struct strGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawWTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";

};

short HowManyRounds()
{

	short GameRounds = 1;

	do
	{

		cout << "How Many Rounds 1 To 10 ? \n";
		cin >> GameRounds;

	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;

}

enGameChoice ReadPlayerChoice()
{
	short Choice = 1;

	do
	{
		cout << "\n Your Chice : [1]:Stone [2]:Paper [3]:Scissors ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice >3);

	return enGameChoice(Choice);
} 

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enGameChoice GetComputerChoice()
{
	
	return enGameChoice(RandomNumber(1,3));
}

enWinner WhoWonTheRound(strRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}
	
		switch (RoundInfo.Player1Choice)
		{

		case enGameChoice::Stone:
		{
			if (RoundInfo.ComputerChoice == enGameChoice::Paper)
				return enWinner::Computer;
			break;
		}

		case enGameChoice::Paper:
		{
			if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
				return enWinner::Computer;
			break;
		}

		case enGameChoice::Scissor:
		{
			if (RoundInfo.ComputerChoice == enGameChoice::Stone)
				return enWinner::Computer;
			break;
		}
		
		}

		return enWinner::Player1;
}

string WinnerName(enWinner Winner)
{
	string ArrWinnerName[3]{"Player1","Computer","No Winner" };
	return  ArrWinnerName[Winner - 1];
}

string ChoiceName(enGameChoice Choice)
{
	string ArrChoiceName[3]{ "Stone","Paper","Scissor" };
	return  ArrChoiceName[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	system("color 2F");
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;

	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	default:
		system("color 6F");
		break;
	}

}


void PrintRoundResults(strRoundInfo RoundInfo)
{
	cout << "\n_______________Round[" << RoundInfo.RoundNumber << "]_______________\n";
	cout << "Player Choice :" << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice :" << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner :" << RoundInfo.WinnerName << endl;
	cout << "\n_____________________________________________________\n";
	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

strGameResults FillGameResilts(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
	strGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrawWTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(GameResults.Player1WinTimes, GameResults.Computer2WinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

strGameResults PlayGame(short HowManyRounds)
{

	strRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);


		if (RoundInfo.Winner == enWinner::Draw)
			DrawTimes++;
		else if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else
			ComputerWinTimes++;




		PrintRoundResults(RoundInfo);
	}

	return FillGameResilts(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";

	for (short i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;

}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "_____________________________________________________\n\n";
	cout << Tabs(2) << "             +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "_____________________________________________________\n\n";
}

void ShowFinalGameResults(strGameResults GameResults)
{
	cout << Tabs(2) << "_______________________Game Results_______________________\n\n";
	cout << Tabs(2) << "Game Rounds         :" << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 Win Times   :" << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer2 Win Times :" << GameResults.Computer2WinTimes << endl;
	cout << Tabs(2) << "Draw Times          :" << GameResults.DrawWTimes << endl;
	cout << Tabs(2) << "Winner Name         :" << GameResults.WinnerName << endl;
	cout << Tabs(2) << "__________________________________________________________\n\n";
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgin = 'Y';

	do
	{
		ResetScreen();
		strGameResults GameResults = PlayGame(HowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << Tabs(3) << "Do You Want To Play Again? Y/N ? ";
		cin >> PlayAgin;

	} while ((PlayAgin == 'Y') || (PlayAgin == 'y'));

}

int main()
{ 
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}