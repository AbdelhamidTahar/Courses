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


void PrintDigits(int  Number)
{

    int Remainder;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder << endl;
    }

}


int main()
{

    PrintDigits(ReadPositiveNumber("Please Enter A Positive Number"));
    
    return 0;
}