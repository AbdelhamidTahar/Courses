#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"

int main()

{
    //while (true)
    //{
    //    if (!clsLoginScreen::ShowLoginScreen())
    //    {
    //        break;
    //    }

    //}
    clsCurrency c1 = clsCurrency::FingByCode("USD");
    if (c1.IsEmpty())
    {
        cout << "Not Found";
    }
    else
    {
        cout << "Found\n";
        cout << c1.Code() << endl;
        cout << c1.Country() << endl;
        if (clsCurrency::IsExist("Algeria"));
            cout << "yes";
        c1 = clsCurrency::FingByCountry("Algeria");
        c1.SetExchangeRate(99.00);
        cout << c1.ExchangeRate() << endl;

    }

    return 0;
}

