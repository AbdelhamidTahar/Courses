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


int CountDigitFrequency(short DigitToCheck, int Number)
{

    int FreqCount = 0;
    int Remainder = 0;
    
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;

        if (Remainder == DigitToCheck)
        {
            FreqCount++;
        }

    }

    return FreqCount;
}


int main()
{

    int Number = ReadPositiveNumber("Please enter a main number?");
    short DigitToCheck = ReadPositiveNumber("Please enter one digit to check?");

    cout << "\nDigit " << DigitToCheck << "Frequency is "
        << CountDigitFrequency(DigitToCheck, Number) << " Time(s).\n";


    return 0;
}