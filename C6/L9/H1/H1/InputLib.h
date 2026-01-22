#pragma once


#include <iostream>
using namespace std;


namespace User_Input
{

    int ReadPositiveNumber(string Message)
    {
        int Number = 0;  // Variable to store the user's input, initialized to 0.
        do
        {
            // Display the prompt message to the user.
            cout << Message << endl;
            // Read the number entered by the user.
            cin >> Number;
        } while (Number <= 0);  // Continue prompting if the number is not positive.

        return Number;  // Return the valid positive number.
    }

    int ReadNumber(string Message)
    {
        int Number = 0;  // Variable to store the user's input, initialized to 0.

        cout << Message << endl;
        // Read the number entered by the user.
        cin >> Number;


        return Number;  // Return the valid positive number.
    }

}
