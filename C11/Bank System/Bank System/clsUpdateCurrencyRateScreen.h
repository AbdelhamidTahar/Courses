#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
//#include ""
using namespace std;

class clsUpdateCurrencyRateScreen :protected clsScreen
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
public:
	static void ShowUpdateCurrencyRateScreen()
	{
        _DrawScreenHeader("\t Update Currency Rate");

		string Code = clsInputValidate::ReadAlphaString("Please Enter Currency Code: ");
		clsCurrency Currency = clsCurrency::FindByCode(Code);
        _PrintCurrency(Currency);

        cout << "Are you sure you want to update the rate of this Currency y/n? :";
        char Answer = clsInputValidate::ReadYesNoAnswer();
        if (Answer)
        {
            cout << "Update Currency Rate:\n";
            cout << "________________________\n";
            cout << "Enter New Rate: ";
            Currency.UpdateRate(clsInputValidate::ReadFloatNumber());
            cout << "Currency Rate Updated Successfully :- )\n";
            _PrintCurrency(Currency);
        }
        cout << "Currency Rate Updated Canseled :- (\n";
	}
};

