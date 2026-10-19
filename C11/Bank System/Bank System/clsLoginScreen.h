#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"
#include "clsMainScreen.h"
using namespace std;

class clsLoginScreen :protected clsScreen
{
private:
	static void _Login()
	{
		string UserName, Password;

		UserName = clsInputValidate::ReadAlphaNumericString("Enter UserName : ");
		Password = clsInputValidate::ReadAlphaNumericString("Enter Password : ");

		while (!clsUser::IsUserExist(UserName, Password))
		{
			cout << "\nInvalid User Name/Password\n";
			UserName = clsInputValidate::ReadAlphaNumericString("Enter UserName : ");
			Password = clsInputValidate::ReadAlphaNumericString("Enter Password : ");
		}

		CurrentUser = clsUser::Find(UserName, Password);
		clsMainScreen::ShowMainMenue();

	}
public:
	static void ShowLoginScreen()
	{
		clsScreen::_DrawScreenHeader("\tLogin Screen");
		_Login();
	}
	

};

