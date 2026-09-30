#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
	bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}
	bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}
	bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate)
	{
		if (clsDate::CompareDates(FromDate, ToDate) == clsDate::After)
			clsDate::SwapDates(FromDate, ToDate);

		return!(clsDate::CompareDates(Date, FromDate) == clsDate::Before
				||
				clsDate::CompareDates(Date, ToDate) == clsDate::After);
	}

	int ReadIntNumber(string Message= "Invalid input. Please try again by entering a valid input.")
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
	double ReadDoubleNumber(string Message= "Invalid input. Please try again by entering a valid input.")
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
	float ReadFloatNumber(string Message= "Invalid input. Please try again by entering a valid input.")
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

	int ReadIntNumberBetween(string Message, int From, int To)
	{
		int Number = ReadIntNumber();

		while ((Number < From) || (Number > To))
		{
			cout << Message << endl;
			Number = ReadIntNumber();
		}

		return Number;
	}
	double ReaddoubleNumberBetween(string Message, double From, double To)
	{
		double Number = ReadDoubleNumber();

		while ((Number < From) || (Number > To))
		{
			cout << Message << endl;
			Number = ReadDoubleNumber();
		}

		return Number;
	}
	float ReadfloatNumberBetween(string Message, float From, float To)
	{
		float Number = ReadFloatNumber();

		while ((Number < From) || (Number > To))
		{
			cout << Message << endl;
			Number = ReadFloatNumber();
		}

		return Number;
	}


	bool IsValidDate(clsDate Date)
	{

		if (Date.Month < 1 || Date.Month > 12)
			return false;
		int NumberOfDaysInAMonth = clsDate::NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day <1 || Date.Day >NumberOfDaysInAMonth)
			return false;

		return true;
	}


};

