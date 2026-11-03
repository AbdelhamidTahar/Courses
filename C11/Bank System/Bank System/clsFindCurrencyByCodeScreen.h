#pragma once
#include<iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"
using namespace std;

class clsFindCurrencyByCodeScreen
{
private :
	static void _PrintCurrencyCard(clsCurrency Card)
	{
		cout << "____________________\n";
		cout << "|"<<Card.Country() << endl;
		cout << "|" << Card.CurrencyCode() << endl;
		cout << "|"<< Card.CurrencyName() << endl;
		cout << "|"<< Card.Rate() << endl;
		cout << "____________________\n";
	}
public:
	static void ShowFindCurrencyByCodeScreen()
	{
		if (Currency.IsEmpty())
		{
			cout << "Not Found By this Code We Are SORRY\n";
		}
		else
		{
			_PrintCurrencyCard(Currency);
		}
		
	}
};

