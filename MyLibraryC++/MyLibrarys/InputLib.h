#pragma once

#include <iostream>
#include <limits>
using namespace std;



namespace Validate
{

    bool IsInputNumberError();

}
namespace User_Input
{

    int ReadPositiveNumber(string Message);

    int ReadNumber(string Message);

}


bool Validate::IsInputNumberError()
{
    bool InputError = false;

    /* cin.fail() return true
    when use don't input number.
    true = errour input*/
    InputError = cin.fail();

    if (InputError == false)
    {
        return false;
    }
    else
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return InputError;
    }

}


int User_Input::ReadPositiveNumber(string Message)
{
    bool InputError = false;
    int Number = 0;  // Variable to store the user's input, initialized to 0.

    do
    {
        // Display the prompt message to the user.
        cout << Message << endl;
        // Read the number entered by the user.
        cin >> Number;

        InputError = Validate::IsInputNumberError();

    } while ((Number <= 0) || (InputError == true));  // Continue prompting if the number is not positive.

    return Number;  // Return the valid positive number.
}

int User_Input::ReadNumber(string Message)
{
    bool InputError = false;
    int Number = 0;  // Variable to store the user's input, initialized to 0.

    do
    {

        cout << Message << endl;
        // Read the number entered by the user.
        cin >> Number;
        InputError = Validate::IsInputNumberError();


    } while (InputError == true);


    return Number;  // Return the valid positive number.
}