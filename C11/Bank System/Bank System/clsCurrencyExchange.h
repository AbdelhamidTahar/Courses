#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyExchange :protected clsScreen
{
private:
    enum enCurrencyExchangeOptions
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateRate = 3,
        eCurrencyCalculator = 4,
        eMainMenue = 5
    };

    static short _ReadCurrencyExchangeOption()
    {
        cout << "Please Enter Your Choice Betweem 1 - 5: ";
        return clsInputValidate::ReadShortNumberBetween(1, 5, "Number is Not Within range, Enter Number Between 1 - 5: ");

    }

    static void _ShowListCurrenciesScreen()
    {
        cout << "ShowListCurrenciesScreen Well Be Here\n";
    }

    static void _ShowUpdateCurrenciesScreen()
    {
        cout << "ShowUpdateCurrenciesScreen Well Be Here\n";
    }

    static void _ShowFindCurrenciesScreen()
    {
        cout << "ShowFindCurrenciesScreen Well Be Here\n";
    }

    static void _ShowCurrenciesCalculatorScreen()
    {
        cout << "ShowCurrenciesCalculator:Screen Well Be Here\n";
    }

    static void _GoBackToCurrencyExchangeScreen()
    {
        system("cls");
        ShowCurrencyExchangeMenu();
    }

    static void _PerfurmCurrencyExchangeShoice(enCurrencyExchangeOptions CurrencyExchangeOptions)
	{
        switch (CurrencyExchangeOptions)
        {
        case enCurrencyExchangeOptions::eListCurrencies:
        {
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }
        case enCurrencyExchangeOptions::eFindCurrency:
        {
            _ShowFindCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }
        case enCurrencyExchangeOptions::eUpdateRate:
        {
            _ShowUpdateCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }
        case enCurrencyExchangeOptions::eCurrencyCalculator:
        {
            _ShowCurrenciesCalculatorScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        }
        case enCurrencyExchangeOptions::eMainMenue:
        {

            break;
        }
        }
	}
public:


    static void ShowCurrencyExchangeMenu()
    {

        system("cls");
        _DrawScreenHeader("\t\tCurrency Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfurmCurrencyExchangeShoice((enCurrencyExchangeOptions)_ReadCurrencyExchangeOption());
    }
};

