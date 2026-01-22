#include <iostream>
#include <string>

using namespace std;


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

int SumOfDigits(int Number)
{
    int Remainder = 0;
    int Sum = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Sum += Remainder;
    }

    return Sum;
}


int main()
{
    
    cout << "\nSum Of Digits = "
        << SumOfDigits(ReadPositiveNumber("Please enter a positive number?"))
        << "\n";

    return 0;
}