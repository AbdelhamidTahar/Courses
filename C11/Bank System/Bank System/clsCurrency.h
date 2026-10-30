#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum _eMode { eEmpty = 1, eUpdate = 2 };

	_eMode _Mode;
	string _Code;
	string _Name;
	string _Country;
	float _ExchangeRate;

	static clsCurrency _ConvertFromLineToObject(string Line)
	{
		vector<string>   Split;
		Split = clsString::Split(Line, "#//#");

		return clsCurrency(_eMode::eUpdate, Split[0], Split[1], Split[2], stof(Split[3]));
	}

	static string _ConvertFromCurrencyObjectToLine(clsCurrency Currency,string Seperater= "#//#")
	{
		string Line = "";

		Line += Currency.Code() + Seperater;
		Line += Currency.Name() + Seperater;
		Line += Currency.Country() + Seperater;
		Line += to_string(Currency.ExchangeRate());

		return Line;
	}

	static vector< clsCurrency> _LoadAllclsCurrencys()
	{
		vector< clsCurrency> Currencys;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertFromLineToObject(Line);
				Currencys.push_back(Currency);
			}
			MyFile.close();
		}

		return Currencys;
	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(_eMode::eEmpty, "", "", "", 0);
	}

	void _SaveListToFile(vector< clsCurrency> CurrencyList)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency& Currency : CurrencyList)
			{
				string Line = _ConvertFromCurrencyObjectToLine(Currency);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}

	void _Save()
	{
		vector< clsCurrency> Currencys = _LoadAllclsCurrencys();
		for (clsCurrency& clsCurrency : Currencys)
		{
			if (_Code == clsCurrency.Code())
			{
				clsCurrency = *this;
				break;
			}
		}
		_SaveListToFile(Currencys);
	}
public:
	clsCurrency(_eMode Mode, string Country, string Code, string Name, float ExchangeRate)
	{
		_Mode = Mode;
		_Code = Code;
		_Name = Name;
		_Country = Country;
		_ExchangeRate = ExchangeRate;
	}
	string Code()
	{
		return _Code;
	}
	string Name()
	{
		return _Name;
	}
	string Country()
	{
		return _Country;
	}
	void SetExchangeRate(float ExchangeRate)
	{
		_ExchangeRate = ExchangeRate;
		_Save();
	}
	float ExchangeRate()
	{
		return _ExchangeRate;
	}

	static clsCurrency FingByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);
		vector< clsCurrency> Currencys = _LoadAllclsCurrencys();
		for (clsCurrency& Currency : Currencys)
		{
			if (Currency.Code() == Code)
			{
				return Currency;
			}
		}
		return _GetEmptyObject();
	}
	static clsCurrency FingByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		vector< clsCurrency> Currencys = _LoadAllclsCurrencys();
		for (clsCurrency& Currency : Currencys)
		{
			if (clsString::UpperAllString(Currency.Country()) == Country)
			{
				return Currency;
			}
		}
		return _GetEmptyObject();
	}
	static vector< clsCurrency> GetCurrencysList()
	{
		return _LoadAllclsCurrencys();
	}
	bool IsEmpty()
	{
		return (_Mode == _eMode::eEmpty);
	}
	static bool IsExist(string Code)
	{
		clsCurrency Currency = FingByCode(Code);
		return (!Currency.IsEmpty());
	}

};

