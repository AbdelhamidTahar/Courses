#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:
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
	static bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate)
	{
		if (clsDate::CompareDates(FromDate, ToDate) == clsDate::After)
			clsDate::SwapDates(FromDate, ToDate);

		return!(clsDate::CompareDates(Date, FromDate) == clsDate::Before
				||
				clsDate::CompareDates(Date, ToDate) == clsDate::After);
	}
	static bool IsValidDate(clsDate Date)
	{

		if (Date.Month < 1 || Date.Month > 12)
			return false;
		int NumberOfDaysInAMonth = clsDate::NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day <1 || Date.Day >NumberOfDaysInAMonth)
			return false;

		return true;
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
	static int ReadIntNumber(string Message= "Invalid input. Please try again by entering a valid input.")
	{
		int Number = 0;
		cin >> Number;
		bool IsError = cin.fail(); // is input error?.

		while (IsError)
		{
			cin.clear();// clear error
			cout << Message << endl;
			cin >> Number;
		    IsError = cin.fail(); // is input error?.
		}

		return Number;
	}
	static double ReadDoubleNumber(string Message= "Invalid input. Please try again by entering a valid input.")
	{
		double Number = 0;
		cin >> Number;
		bool IsError = cin.fail(); // is input error?.

		while (IsError)
		{
			cin.clear();// clear error
			cout << Message << endl;
			cin >> Number;
			IsError = cin.fail(); // is input error?.
		}

		return Number;
	}
	static float ReadFloatNumber(string Message= "Invalid input. Please try again by entering a valid input.")
	{
		float Number = 0;
		cin >> Number;
		bool IsError = cin.fail(); // is input error?.

		while (IsError)
		{
			cin.clear();// clear error
			cout << Message << endl;
			cin >> Number;
			IsError = cin.fail(); // is input error?.
		}

		return Number;
	}
	static int ReadIntNumberBetween(string Message, int From, int To)
	{
		int Number = ReadIntNumber();

		while ((Number < From) || (Number > To))
		{
			cout << Message << endl;
			Number = ReadIntNumber();
		}

		return Number;
	}
	static double ReaddoubleNumberBetween(string Message, double From, double To)
	{
		double Number = ReadDoubleNumber();

		while ((Number < From) || (Number > To))
		{
			cout << Message << endl;
			Number = ReadDoubleNumber();
		}

		return Number;
	}
	static float ReadfloatNumberBetween(string Message, float From, float To)
	{
		float Number = ReadFloatNumber();

		while ((Number < From) || (Number > To))
		{
			cout << Message << endl;
			Number = ReadFloatNumber();
		}

		return Number;
	}
	string ReadAlphaString(const string& InputMessage, const string& ErrorMessage)
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




};

