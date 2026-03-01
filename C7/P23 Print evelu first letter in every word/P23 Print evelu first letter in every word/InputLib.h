#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
using namespace std;



namespace Validate
{

    bool IsInputNumberError();
    bool IsStringHasDigits(const string& Text);
    bool IsStringHaspunct(const string& Text);
    bool IsStringHasDigitOrPunct(const string& Text);

}
namespace User_Input
{

    int ReadPositiveNumber(string Message);

    int ReadNumber(string Message);

    string ReadString();

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

string User_Input::ReadString()
{
    cout << "Please Enter Your String: \n";
    string Text;
    getline(cin, Text);
    return Text;
}

bool Validate::IsStringHasDigits(const string& Text)
{
    unsigned int LengthOfText = Text.length();
    for (int i = 0; i < ceil(LengthOfText) / 2; i++)
    {

        if (isdigit(Text[i]) || isdigit(Text[LengthOfText - i - 1]))
        {
            return true;
        }
    }
    return false;
}

bool Validate::IsStringHaspunct(const string& Text)
{
    unsigned int LengthOfText = Text.length();
    for (int i = 0; i < ceil(LengthOfText) / 2; i++)
    {

        if (ispunct(Text[i]) || ispunct(Text[LengthOfText - i - 1]))
        {
            return true;
        }
    }
    return false;
}

bool Validate::IsStringHasDigitOrPunct(const string& Text)
{
    return (IsStringHasDigits(Text) || IsStringHaspunct(Text));
}