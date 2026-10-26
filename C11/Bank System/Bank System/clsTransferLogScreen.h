#pragma once
#include <iostream > 
#include <vector >
#include <iomanip >
#include "clsScreen.h"
#include "clsString.h"
#include "clsBankClient.h"
using namespace std;

class clsTransferLogScreen :protected clsScreen
{
private:

	static void _PrintTransfersLogrecord(clsBankClient::_stTransferLog TransferLogrecord)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLogrecord.DateAndTime;
		cout << "| " << setw(12) << left << TransferLogrecord.AccountNumberSourceClient;
		cout << "| " << setw(12) << left << TransferLogrecord.AccountNumberDestinationClient;
		cout << "| " << setw(12) << left << TransferLogrecord.Amount;
		cout << "| " << setw(12) << left << TransferLogrecord.SourceClientAmount;
		cout << "| " << setw(12) << left << TransferLogrecord.DestinationClientAmount;
		cout << "| " << setw(12) << left << TransferLogrecord.UserName;
	}
public:
	static void ShowTransferLogScreen()
	{
		vector< clsBankClient::_stTransferLog>TransfersLogList = clsBankClient::GetTransfersLogList();
		string Titel = "\tTransfers Log List";
		string SubTitle = "\t(" + to_string(TransfersLogList.size()) + "Record(s)";

		_DrawScreenHeader(Titel,SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(12) << "s.Acct";
		cout << "| " << left << setw(12) << "d.Acct";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << "s. Balance";
		cout << "| " << left << setw(12) << "d. Balance";
		cout << "| " << left << setw(12) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (TransfersLogList.size() == 0)
			cout << "\t\t\tNot Found\n";
		else
		{
			for (clsBankClient::_stTransferLog& stTransferLog : TransfersLogList)
			{
				_PrintTransfersLogrecord(stTransferLog);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

	}
};

