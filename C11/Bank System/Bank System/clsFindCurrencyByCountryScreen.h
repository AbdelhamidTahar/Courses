#pragma once
#include<iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"
using namespace std;

class clsFindCurrencyByCountryScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Card)
	{
		cout << "____________________\n";
		cout << "|" << Card.Country() << endl;
		cout << "|" << Card.CurrencyCode() << endl;
		cout << "|" << Card.CurrencyName() << endl;
		cout << "|" << Card.Rate() << endl;
		cout << "____________________\n";
	}
public:
	static void ShowFindCurrencyByCountryScreen()
	{

	
		if (Currency.IsEmpty())
		{
			cout << "Not Found By this Country Name We Are SORRY\n";
		}
		else
		{
			_PrintCurrencyCard(Currency);
		}

	}
};

