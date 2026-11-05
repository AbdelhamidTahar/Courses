#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsInputValidate
{
public:
	template<typename T>static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (IsNumberBetween<short>(Number, From, To));
	}
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (IsNumberBetween<int>(Number, From, To));

	}
	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (IsNumberBetween<float>(Number, From, To));
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (IsNumberBetween<double>(Number, From, To));
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

	template<typename T> static bool IsPositiveNumber(T Number)
	{
		return (Number > 0);
	}
	static bool IsPositiveNumber(int Number)
	{
		return (IsPositiveNumber<int>(Number));
	}
	static bool IsPositiveNumber(short Number)
	{
		return (IsPositiveNumber<short>(Number));
	}
	static bool IsPositiveNumber(float Number)
	{
		return (IsPositiveNumber<float>(Number));
	}
	static bool IsPositiveNumber(double Number)
	{
		return (IsPositiveNumber<double>(Number));
	}

	template<typename T> static bool IsNegativeNumber(T Number)
	{
		return (Number < 0);
	}
	static bool IsNegativeNumber(int Number)
	{
		return (IsNegativeNumber<int>(Number));
	}
	static bool IsNegativeNumber(short Number)
	{
		return (IsNegativeNumber<short>(Number));
	}
	static bool IsNegativeNumber(float Number)
	{
		return (IsNegativeNumber<float>(Number));
	}
	static bool IsNegativeNumber(double Number)
	{
		return (IsNegativeNumber<double>(Number));
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
	static bool IsStringHasPunctuation(const string& Input)
	{
		for (const char& Character : Input)
		{
			if (ispunct(Character))
				return true;
		}
		return false;

	}
	static bool IsStringHasDigit(const string& Input)
	{
		for (const char& Character : Input)
		{
			if (isdigit(Character))
				return true;
		}
		return false;

	}
	static bool IsStringHasLetter(const string& Input)
	{
		for (const char& Character : Input)
		{
			if (isalpha(Character))
				return true;
		}
		return false;

	}
	static bool IsStringHasSpace(const string& Input)
	{
		for (char C : Input)
		{
			if (C == ' ')
				return true;
		}
		return false;
	}

	template<typename T>static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;

		while (!(cin >> Number))
		{
			cin.clear();// clear error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}

		return Number;
	}
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNumber<int>(ErrorMessage);
	}

	template<typename T>static  T ReadPositiveNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;

		while (!(cin >> Number) || IsNegativeNumber<T>(Number))
		{
			cin.clear();// clear error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}

		return Number;
	}
	template<typename T>static T ReadNegativeNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;

		while (!(cin >> Number) || IsPositiveNumber<T>(Number))
		{
			cin.clear();// clear error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}

		return Number;
	}

	static int ReadPositiveIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadPositiveNumber<int>(ErrorMessage);
	}
	static int ReadNegativeIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNegativeNumber<int>(ErrorMessage);
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNumber<short>(ErrorMessage);
	}
	static short ReadPositiveShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadPositiveNumber<short>(ErrorMessage);

	}
	static short ReadNegativeShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNegativeNumber<short>(ErrorMessage);

	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNumber<float>(ErrorMessage);

	}
	static float ReadPositiveFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadPositiveNumber<float>(ErrorMessage);

	}
	static float ReadNegativeFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNegativeNumber<float>(ErrorMessage);
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNumber<double>(ErrorMessage);
	}
	static double ReadPositiveDbNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadPositiveNumber<double>(ErrorMessage);

	}
	static double ReadNegativeDbNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		return ReadNegativeNumber<double>(ErrorMessage);

	}


	template <typename T>static  T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween<T>(Number, From, To))
		{
			cout << ErrorMessage << endl;
			Number = ReadNumber<T>();
		}

		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		return ReadNumberBetween<int>(From, To, ErrorMessage);
	}
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		return ReadNumberBetween<double>(From, To, ErrorMessage);
	}
	static float ReadfloatNumberBetween(string Message, float From, float To)
	{
		return ReadNumberBetween<float>(From, To, Message);
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		return ReadNumberBetween<short>(From, To, ErrorMessage);
	}

	static string ReadAlphaString(const string& InputMessage, const string& ErrorMessage = "Invalid input. Numbers or punctuation not allowed.\n")
	{
		string AlphaString = "";
		cout << InputMessage;
		getline(cin >> ws, AlphaString);

		while (IsStringHasPunctuation(AlphaString)
			          ||
			IsStringHasDigit(AlphaString)
			          ||
			IsStringHasSpace(AlphaString))
		{
			cout << ErrorMessage;

			cout << InputMessage;
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
	static string ReadAlphaNumericString(const string& InputMessage, const string& ErrorMessage = "Invalid input. punctuation or space are not allowed.\n")
	{
		string S1 = "";
		cout << InputMessage;
		S1 = ReadString();

		while (IsStringHasPunctuation(S1) || IsStringHasSpace(S1))
		{
			cout << ErrorMessage;

			cout << InputMessage;
			S1 = ReadString();
		}

		return S1;
	}
	static string ReadAccountNumber(const string& InputMessage)
	{
		
		return ReadAlphaNumericString(InputMessage);
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
	static char ReadChar()
	{
		char C;
		cin >> C;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return C;
	}
	static bool ReadYesNoAnswer()
	{
		char Answer = ReadChar();
		return (Answer == 'y' || Answer == 'Y');
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

