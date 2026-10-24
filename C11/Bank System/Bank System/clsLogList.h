#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsScreen.h"
#include "clsString.h"
using namespace std;

struct stLoginData
{
	string DateAndTine;
	string Username;
	string Password;
	string Permision;
};

class clsLogList :protected clsScreen
{
private:

	static stLoginData _ConvertDataLineLogTostLoginData(string LogDataLin)
	{
		vector<string>vDataLog = clsString::Split(LogDataLin, "#//#");
		stLoginData LoginData;
		LoginData.DateAndTine = vDataLog[0];
		LoginData.Username = vDataLog[1];
		LoginData.Password = vDataLog[2];
		LoginData.Permision = vDataLog[3];

		return LoginData;
	}

	static vector <stLoginData> _LoadLogsData()
	{
		vector <stLoginData> vLoginData;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string LogDataLin;
			while (getline(MyFile, LogDataLin))
			{
				stLoginData LoginData;
				LoginData = _ConvertDataLineLogTostLoginData(LogDataLin);
				vLoginData.push_back(LoginData);
			}
		}
		MyFile.close();

		return vLoginData;
	}

   static vector <stLoginData> _GetLoginList()
   	{
   		return _LoadLogsData();
   	}

   static void _PrintLoginDataRecord(stLoginData Record)
   {
	   cout << left;
	   cout << setw(10) << "|";
	   cout << left << setw(40) << Record.DateAndTine;
	   cout << left << "|" << setw(20) << Record.Username;
	   cout << left << "|" << setw(20) << Record.Password;
	   cout << left << "|" << setw(20) << Record.Permision;
	   cout << right << setw(5) << "|";
   }

public :

	

	static void ShowLogListScreen()
	{
		vector <stLoginData> vLoginData = _GetLoginList();

		string Title = "\tLogin Regester List Screen\n";
		string SubTitle = "\t\t" + to_string(vLoginData.size()) + " Recod(s).";

		_DrawScreenHeader(Title, SubTitle);

		//cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";

		cout << "\n____________________________________________________________";
		cout << "____________________________________________________\n";
		
		cout << setw(10) << "|";
		cout << left << setw(40) << "Date And Tine";
		cout << left << "|" << setw(20) << "Username";
		cout << left << "|" << setw(20) << "Password";
		cout << left << "|" << setw(20) << "Permissions";
		cout << right << setw(5) << "|";

		cout << "\n____________________________________________________________";
		cout << "____________________________________________________\n";

		for (stLoginData &LoginData: vLoginData)
		{
			_PrintLoginDataRecord(LoginData);
			cout << endl;
		}
	}
};

