#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransactionsMenueScreen :protected clsScreen
{
private:
    enum _enTransactionsChoice { enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enMainMenue = 4 };

    static void _ShowDepositScreen()
    {
        cout << "Deposit Screen Well Be Here\n";
    }

    static void _ShowWithdrawScreen()
    {
        cout << "Withdraw Screen Well Be Here\n";
    }

    static void _ShowTotalBalancesScreen()
    {
        cout << "Total Balances Screen Well Be Here\n";
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

        system("pause>0");
        ShowTransactionsMenueScreen();
    }

    static void _PerfurmTransactionsChoice(_enTransactionsChoice TransactionsChoice)
    {
        switch (TransactionsChoice)
        {
        case _enTransactionsChoice::enDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case _enTransactionsChoice::enWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case _enTransactionsChoice::enTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case _enTransactionsChoice::enMainMenue:
        {

        }
        }
    }
   
    static short _ReadTransactionsChoice()
    {
        cout << "Please Enter Your Choice From [1-4]: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4);

        return Choice;
    }

public:
	static void ShowTransactionsMenueScreen()
	{
        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfurmTransactionsChoice((_enTransactionsChoice)_ReadTransactionsChoice());
	}
};

