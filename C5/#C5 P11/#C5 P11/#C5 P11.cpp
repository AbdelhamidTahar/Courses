#include <iostream>
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

int ReverseNumber(int Number)
{

    int Remainder = 0;
    int Number2 = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }

    return Number2;
}

bool IsPalindromeNumber(int Number)
{
    return Number == ReverseNumber(Number);
}


int main()
{
    if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number?")))

        cout << "\nYes , it is a Palindrome number.\n";  
    else
        cout << "\nNo , it is NOT a Palindrome number.\n"; 

    return 0;  
}