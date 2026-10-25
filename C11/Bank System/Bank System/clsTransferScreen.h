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
	static string _ReadAccountNumber(string AccountNumber1)
	{
		string AccountNumber = "";

		bool IsTheSameAccount = false;

		do
		{
			if (IsTheSameAccount)
				cout << "Invalid transfer: Source and destination accounts cannot be the same. Please try again.\n";
			do
			{
				cout << "Please enter the account number from which you wish to transfer: ";
				AccountNumber = clsInputValidate::ReadString();
			} while (!clsBankClient::IsClientExist(AccountNumber));

			IsTheSameAccount = AccountNumber1 == AccountNumber;
		} while (IsTheSameAccount);

		return AccountNumber;
	}

	static double _ReadAmmount(clsBankClient Client)
	{
		cout << "Please Enter Amount Do You Want To Transfar: ";
		double Amount;
		Amount = clsInputValidate::ReadDblNumber();
		while (!Client.IsAccountBalanceEngthf(Amount))
		{
			cout << "Error: You cannot transfer more than your available balance. Please try again\n";
			cout << "Please Enter Amount Do You Want To Transfar: ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;
	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient Client1 = clsBankClient::Find(_ReadAccountNumber(""));
		_PrintClient(Client1);


		clsBankClient Client2 = clsBankClient::Find(_ReadAccountNumber(Client1.AccountNumber()));
		_PrintClient(Client2);

		cout << "Enter How Many Amount To Transfer:";
		double Amount = _ReadAmmount(Client1);

		char Answer = 'n';
		cout << "Do you want to done this transfer: ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Transfar(Client2, Amount))
				cout << "Transfar Done\n";
			else
				cout << "Error\n";
		}
		else
			cout << "Transfar Is Canseled\n";
		
	}


};

