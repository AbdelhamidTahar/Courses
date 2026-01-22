#pragma once

#include <iostream>
#include <limits>
using namespace std;

namespace Validate
{

    bool ValidateNumber()
    {
        bool InputError = false;
        InputError = cin.fail();

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return InputError;

    }

}

namespace User_Input
{

    int ReadPositiveNumber(string Message)
    {
        bool InputError = false;
        int Number = 0;  // Variable to store the user's input, initialized to 0.

        do
        {
            // Display the prompt message to the user.
            cout << Message << endl;
            // Read the number entered by the user.
            cin >> Number;

            InputError = Validate::ValidateNumber();

        } while ((Number <= 0) || (InputError == true));  // Continue prompting if the number is not positive.

        return Number;  // Return the valid positive number.
    }

    int ReadNumber(string Message)
    {
        bool InputError = false;
        int Number = 0;  // Variable to store the user's input, initialized to 0.

        do
        {

            cout << Message << endl;
            // Read the number entered by the user.
            cin >> Number;
            InputError = Validate::ValidateNumber();


        } while (InputError == true);


        return Number;  // Return the valid positive number.
    }

}


