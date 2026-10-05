#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}
	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
	static bool IsHasPunctuation(const string& Input)
	{
		for (const char& Character : Input)
		{
			if (ispunct(Character))
				return true;
		}
		return false;

	}
	static bool IsHasDigit(const string& Input)
	{
		for (const char& Character : Input)
		{
			if (isdigit(Character))
				return true;
		}
		return false;

	}
	static bool IsHasChar(const string& Input)
	{
		for (const char& Character : Input)
		{
			if (isalpha(Character))
				return true;
		}
		return false;

	}
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number ;

		while (!(cin >> Number))
		{
			cin.clear();// clear error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}

		return Number;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;


		while (!(cin >> Number))
		{
			cin.clear();// clear error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}

		return Number;
	}

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage << endl;
			Number = ReadIntNumber();
		}

		return Number;
	}
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number,From,To))
		{
			cout << ErrorMessage << endl;
			Number = ReadDblNumber();
		}

		return Number;
	}
	static float ReadfloatNumberBetween(string Message, float From, float To)
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message << endl;
			Number = ReadFloatNumber();
		}

		return Number;
	}
	static string ReadAlphaString(const string& InputMessage, const string& ErrorMessage)
	{
		string AlphaString = "";
		cout << InputMessage << endl;
		getline(cin >> ws, AlphaString);

		while (IsHasPunctuation(AlphaString) || IsHasDigit(AlphaString))
		{
			cout << ErrorMessage << endl << endl;

			cout << InputMessage << endl;
			getline(cin >> ws, AlphaString);
		}
		return AlphaString;
	}
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
	static char ReadLetter(const string &ErrorMessage = "Invalid Letter, Enter again\n")
	{
		char Letter;

		cin >> Letter;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		while (!isalpha(Letter))
		{
			cout << ErrorMessage;
			cin >> Letter;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}

		return Letter;
	}
	static short ReadDigit(const string& ErrorMessage = "Invalid Digit, Enter again\n")
	{
		char Digit;
		cin >> Digit;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		while (!isdigit(Digit))
		{
			cout << ErrorMessage;
			cin >> Digit;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (short(Digit)) // Convert From ASCII to DICIMAL Digit.
		{
		case 48:return 0;
		case 49:return 1;
		case 50:return 2;
		case 51:return 3;
		case 52:return 4;
		case 53:return 5;
		case 54:return 6;
		case 55:return 7;
		case 56:return 8;
		case 57:return 9;
		}

		
	}


};

