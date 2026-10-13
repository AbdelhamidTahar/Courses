#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"


//void UpdateClient()
//{
//    string AccountNumber = "";
//
//    cout << "\nPlease Enter client Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount number is not found, choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//    Client1.Print();
//
//    cout << "\n\nUpdate Client Info:";
//    cout << "\n____________________\n";
//
//
//    ReadClientInfo(Client1);
//
//    clsBankClient::enSaveResults SaveResult;
//
//    SaveResult = Client1.Save();
//
//    switch (SaveResult)
//    {
//    case  clsBankClient::enSaveResults::svSucceeded:
//    {
//        cout << "\nAccount Updated Successfully :-)\n";
//        Client1.Print();
//        break;
//    }
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//    {
//        cout << "\nError account was not saved because it's Empty";
//        break;
//
//    }
//
//    }
//}
//
//
//
//
// void _PrintClientRecordBalanceLine(clsBankClient Client)
//{
//
//    cout << "| " << setw(15) << left << Client.AccountNumber();
//    cout << "| " << setw(40) << left << Client.FullName();
//    cout << "| " << setw(34) << left << Client.AccountBalance << "|";
//
//}
//
//void ShowTotalBalances()
//{
//
//    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
//
//    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    cout << "| " << left << setw(15) << "Accout Number";
//    cout << "| " << left << setw(40) << "Client Name";
//    cout << "| " << left << setw(34) << "Balance";
//    cout << "|";
//
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    double TotalBalances = clsBankClient::GetTotalBalances();
//
//    if (vClients.size() == 0)
//        cout << "\t\t\t\tNo Clients Available In the System!";
//    else
//
//        for (clsBankClient Client : vClients)
//        {
//            _PrintClientRecordBalanceLine(Client);
//            cout << endl;
//        }
//
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
//    cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
//}

int main()

{
    clsMainScreen::ShowMainMenue();
    system("pause>0");
    return 0;
}