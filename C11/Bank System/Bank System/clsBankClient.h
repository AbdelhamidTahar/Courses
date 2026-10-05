#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;

class clsBankClient:public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		clsBankClient c1(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

		return c1;

	}

	 string _ConvertClientObjectLine(clsBankClient Client, string Seperator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber() + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}


	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	vector< clsBankClient> _LoeadClientsDataFromFile()
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			vector< clsBankClient> vClients;
			string Line;
			while(getline(MyFile, Line))
			{
				vClients.push_back(_ConvertLinetoClientObject(Line));
			}
			MyFile.close();
			return vClients;
		}
	}

	void _SaveClientsdataToFile(vector< clsBankClient>vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
				MyFile << _ConvertClientObjectLine(C) << endl;
		}
	}

	void _UpdateClientsData()
	{
		vector< clsBankClient>vClients;
		vClients = _LoeadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsdataToFile(vClients);
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	
	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;


			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName  : " << FirstName;
		cout << "\nLastName   : " << LastName;
		cout << "\nFull Name  : " << FullName();
		cout << "\nEmail      : " << Email;
		cout << "\nPhone      : " << Phone;
		cout << "\nAcc. Number: " << AccountNumber();
		cout << "\nPassword   : " << PinCode;
		cout << "\nBalance    : " << AccountBalance;
		cout << "\n___________________\n";

	}

	enum enReturnSaveMode { enErrorEmptySave = 0, enUpdateSecsusfly = 1 };
	enReturnSaveMode Save()
	{
		switch (_Mode)
		{
		case(enMode::EmptyMode):
		{
			return enReturnSaveMode::enErrorEmptySave;
		}
		case(enMode::UpdateMode):
		{
			_UpdateClientsData();
			return enReturnSaveMode::enUpdateSecsusfly;
		}

		}
	}

};

