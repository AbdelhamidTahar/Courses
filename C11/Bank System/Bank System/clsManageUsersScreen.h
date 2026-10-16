#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsManageUsersScreen :protected clsScreen
{
private:
    
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    
    static short _ReadManageUsersMenuOpetion()
    {
        short Option;

        cout << "Please Enter You Opetion Betwing [1-6]; ";
        return Option = clsInputValidate::ReadShortNumberBetween
        (1, 6, "Please Enter You Opetion Betwing [1-6]; ");

    }

    static void _ShowListUsersScreen()
    {
        cout << "Show List Users Screen Well Be Here\n";
    }

    static void _ShowAddNewUserScreen()
    {
        cout << "Show Add New User Screen Well Be Here\n";
    }

    static void _ShowDeleteUserScreen()
    {
        cout << "Show Delete User Screen Well Be Here\n";
    }

    static void _ShowUpdateUserScreen()
    {
        cout << "Show Update User Screen Well Be Here\n";
    }

    static void _ShowFindUserScreen()
    {
        cout << "Show Find User Screen Well Be Here\n";
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }
    


    static void _PerformManageUsersMenueOption
    (enManageUsersMenueOptions ManageUsersMenueOptions)
    {
        switch (ManageUsersMenueOptions)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eAddNewUser:
        {
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eDeleteUser:
        {
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eUpdateUser:
        {
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eFindUser:
        {
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eMainMenue:
        {
            // nothimg we be here.
        }

        }
    }

public:
	static void ShowManageUsersMenue()
	{
        system("cls");
		clsScreen::_DrawScreenHeader("\tManage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenuOpetion());
	}
};

