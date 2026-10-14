#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"



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