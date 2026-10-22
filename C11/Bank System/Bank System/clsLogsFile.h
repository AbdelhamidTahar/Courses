#pragma once
#include <iostream>
#include <fstream>
#include "clsDate.h";
#include "clsTime.h";
#include "Global.h"

using namespace std;

class clsLogsFile
{
private:


	static string _ConvertLoginUserDataToString(string Separeter = "#//#")
	{
		clsDate _SystemDate = clsDate::GetSystemDate();
		clsTime _SystemTime = clsTime::GetSystemTime();

		string DataLine = "";
		
		DataLine += clsDate::DateToString(_SystemDate) + " - " + clsTime::TimeToString(_SystemTime);
		DataLine += Separeter + CurrentUser.UserName;
		DataLine += Separeter + CurrentUser.Password;
		DataLine += Separeter + to_string(CurrentUser.Permissions);

		return DataLine;
	}
	static void _Save(string LogDataLine)
	{
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::app);

		if (MyFile.is_open())
			MyFile << LogDataLine << endl;

		return;
	}
protected:
	static void SaveLoginUserDataToFile()
	{
		
		_Save(_ConvertLoginUserDataToString());

	}
};

