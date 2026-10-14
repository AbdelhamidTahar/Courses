#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsDepositScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    enum _enDepositMode{enDoneDeposit,enErrorDeposit};


public:
    static void ShowDepositScreen()
    {
        cout << "\n-----------------------------------\n";
        cout << "\tDeposit Screen";
        cout << "\n-----------------------------------\n";


        cout << "Please Enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            cout << "Please Enter Account Number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nPlease enter deposit amount? ";
        double Amount = clsInputValidate::ReadDblNumber();

        char Answer = 'n';


        cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
        cin >> Answer;
        if (Answer == 'n' || Answer == 'N')
            return;

        Client.AccountBalance += Amount;

        if (Client.Save() == clsBankClient::enSaveResults::svSucceeded)
             cout << "Done Deposit\n";
        else
            cout << "Error Deposit\n";
    }


};

