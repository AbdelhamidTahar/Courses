#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	cout << "Please Enter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "Please Enter LastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "Please Enter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "Please Enter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "Please Enter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "Please Enter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}
void UpdateClient()
{
	cout << "Please Enter Account Number: ";
	string AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Sorry, This Client Is Not Excite, Try Another One: ";
		AccountNumber = clsInputValidate::ReadString();
	}


	clsBankClient Clinet = clsBankClient::Find(AccountNumber);
	Clinet.Print();

	ReadClientInfo(Clinet);

	clsBankClient::enReturnSaveMode SaveMode;
	SaveMode = Clinet.Save();

	if (SaveMode == clsBankClient::enReturnSaveMode::enErrorEmptySave)
	{
		cout << "Soory This Object Is Empty Can't Save Empty Object." << endl;
	}
	else if (SaveMode == clsBankClient::enReturnSaveMode::enUpdateSecsusfly)
	{
		Clinet.Print();
		cout << "Update Succsusfly" << endl;
	}
}

int main()
{
	
	UpdateClient();

	return 0;
}