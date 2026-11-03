#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}
	static clsCurrency _ReadCurrency(int NumberOfCurrency)
	{
		cout << "Please Enter Currency " << NumberOfCurrency << " Code:\n";
		string Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurrency Not Found\n";
			cout << "Please Enter Currency " << NumberOfCurrency << " Code:\n";
			Code = clsInputValidate::ReadString();
		}

		return  clsCurrency::FindByCode(Code);
	}
public:
	static void ShowCurrencyCalculatorScreen()
	{
		bool Answer = false;
		do
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator");


			clsCurrency CurrencyFrom = _ReadCurrency(1);
			clsCurrency CurrencyTo = _ReadCurrency(2);

			cout << "Enter Amount To Exchange: ";
			float Amount = clsInputValidate::ReadFloatNumber();

			float AmountAsUSD = clsCurrency::ConvertCurrencyToUSD(CurrencyFrom, Amount);
			_PrintCurrency(CurrencyFrom);
			cout << Amount << " " + CurrencyFrom.CurrencyCode() << " = " << AmountAsUSD << " USD" << endl;

			if (CurrencyTo.CurrencyCode() != "USD")
			{
				float AmountAfterConvert = clsCurrency::ConvertCurrencyFromUSDTo(CurrencyTo, Amount);
				_PrintCurrency(CurrencyTo);
				cout << AmountAsUSD << " USD = " << AmountAfterConvert << " " << CurrencyTo.CurrencyCode() << endl;

			}
			cout << "Do You Want To Prform another calculation? y/n ?: ";
			Answer = clsInputValidate::ReadYesNoAnswer();
		} while (Answer);

	}
};

