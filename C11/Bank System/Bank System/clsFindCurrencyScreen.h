#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsFindCurrencyByCodeScreen.h"
#include "clsFindCurrencyByCountryScreen.h"
#include <iomanip>
using namespace std;

class clsFindCurrencyScreen:protected clsScreen
{
private:
   static short ReadFindCurrencyOptions()
    {
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
        return Choice;
    }
   enum enFindCurrencyOptions
   {
       eByCode = 1,
       eByCountry = 2
   };

   static void _ShowFindCurrencyByCodeScreen()
   {
       //cout << "Well Be Here\n";
       clsFindCurrencyByCodeScreen::ShowFindCurrencyByCodeScreen();
   }

   static void _ShowFindCurrencyByCountryScreen()
   {
       //cout << "Well Be Here\n";
       clsFindCurrencyByCountryScreen::ShowFindCurrencyByCountryScreen();
   }

   static void _PerformFindCurrencyOptions(enFindCurrencyOptions FindCurrencyOptions)
   {
       switch (FindCurrencyOptions)
       {
       case enFindCurrencyOptions::eByCode:
       {
           _ShowFindCurrencyByCodeScreen();
           break;
       }
       case enFindCurrencyOptions::eByCountry:
       {
           _ShowFindCurrencyByCountryScreen();
           break;
       }
       }
   }


public:
	static void ShowFindCurrencyScreen()
	{
        system("cls");
        _DrawScreenHeader("    Find Currency Screen");


        cout << setw(37) << left << "" << "\t Find By [1]Code Or [2]Country? ";

        _PerformFindCurrencyOptions((enFindCurrencyOptions)ReadFindCurrencyOptions());

	}
};

