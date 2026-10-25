#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransferScreen :protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		string AccountNumber = clsInputValidate::ReadAlphaNumericString("Enter Account Number To Transfer From: ");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient Not Exist: \n";
			AccountNumber = clsInputValidate::ReadAlphaNumericString("Enter Account Number To Transfer From: ");
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);


	    AccountNumber = clsInputValidate::ReadAlphaNumericString("Enter Account Number To Transfer To: ");

		while (!clsBankClient::IsClientExist(AccountNumber) || AccountNumber == Client1.AccountNumber())
		{
			cout << "\nClient Not Exist: \n";
			AccountNumber = clsInputValidate::ReadAlphaNumericString("Enter Account Number To Transfer From: ");
		}
		clsBankClient Client2 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client2);

		cout << "Enter How Many Amount To Transfer:";
		double Amount = clsInputValidate::ReadDblNumber();
		while (!Client1.IsAccountBalanceEngthf(Amount))
		{
			cout << "Your Account Balance Is Not Enghf\n";
			cout << "Enter How Many Amount To Transfer:";
		    Amount = clsInputValidate::ReadDblNumber();
		}
		char Answer = 'n';
		cout << "Do you want to done this transfer: ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client1.Transfar(Client2, Amount);
			cout << "Transfar Done\n";
		}
		else
			cout << "Transfar Is Canseled\n";
		
	}


};

