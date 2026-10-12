#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsMainScreen:protected clsScreen
{
private:
	static short _ReadMainMenurChoise()
	{
		cout << "Please Enter Number Betwem [1 to 8]\n";
		short MainMenuChoise = clsInputValidate::ReadShortNumberBetween("error value Please Enter Number Betsen [1 to 8]", 1, 8);
		return MainMenuChoise;
	}

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8
    };

    static void _ShowAllClientsScreen()
    {
		cout << "Clinet List We Be Here\n";
    }

    static void _GoBackToMainMenue()
    {
        cout << "\n\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowMainMenue();
    }

	static void _AddNewClientSecreen()
	{
		cout << "Add New Client We Be Here\n";

	}

	static void _DeleteClientSecreen()
	{
		cout << "Add New Client We Be Here\n";
	}

	static void _UpdateClientInfoSecreen()
	{
		cout << "Update Client Info We Be Here\n";

	}

	static void _FindClientSecreen()
	{
		cout << "Find Client Info We Be Here\n";
	}

	static void _TransactionsSecreen()
	{
		cout << "Transactions Secreen We Be Here\n";

	}
	
	static void _ManageUsersSecreen()
	{
		cout << "Manage UsersS Secreen We Be Here\n";
	}
	
	static void _LogoutSecreen()
	{
		cout << "Logout Secreen We Be Here\n";
	}

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
		switch (MainMenueOption)
		{
		case(enMainMenueOptions::eListClients):
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();

			break;
		}
		case(enMainMenueOptions::eAddNewClient):
		{
			system("cls");
			_AddNewClientSecreen();
			_GoBackToMainMenue();
			break;
		}
		case(enMainMenueOptions::eDeleteClient):
		{
			system("cls");
			_DeleteClientSecreen();
			_GoBackToMainMenue();
			break;
		}
		case(enMainMenueOptions::eUpdateClient):
		{
			system("cls");
			_UpdateClientInfoSecreen();
			_GoBackToMainMenue();
			break;
		}
		case(enMainMenueOptions::eFindClient):
		{
			system("cls");
			_FindClientSecreen();
			_GoBackToMainMenue();
			break;
		}
		case(enMainMenueOptions::eShowTransactionsMenue):
		{
			system("cls");
			_TransactionsSecreen();
			_GoBackToMainMenue();
			break;
		}
		case(enMainMenueOptions::eManageUsers):
		{
			system("cls");
			_ManageUsersSecreen();
			_GoBackToMainMenue();
			break;
		}
		case(enMainMenueOptions::eExit):
		{
			system("cls");
			break;
		}
		}
    }


public:
	static void ShowMainMenue()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("Main Screen");

		cout << "===========================================\n";
		cout << "\t\tMain Menue Screen\n";
		cout << "===========================================\n";
		cout << "\t[1] Show Client List.\n";
		cout << "\t[2] Add New Client.\n";
		cout << "\t[3] Delete Client.\n";
		cout << "\t[4] Update Client Info.\n";
		cout << "\t[5] Find Client.\n";
		cout << "\t[6] Transactions.\n";
		cout << "\t[7] Manage Users.\n";
		cout << "\t[8] Logout.\n";
		cout << "===========================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenurChoise());

	}
};

