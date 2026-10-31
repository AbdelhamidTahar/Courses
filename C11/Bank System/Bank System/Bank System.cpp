#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"

int main()

{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }
   
    return 0;
}

