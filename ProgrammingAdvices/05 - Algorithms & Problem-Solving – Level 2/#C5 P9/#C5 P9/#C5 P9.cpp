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


void PrintAllDigitsFrequencey(int Number)
{
    cout << endl;  

    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0;                         
        DigitFrequency = CountDigitFrequency(i, Number);  

        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is "  
                << DigitFrequency << " Time(s).\n";
        }
    }
}

int main()
{

    int Number = ReadPositiveNumber("Please enter one digit to check?");
    PrintAllDigitsFrequencey(Number);
    


    return 0;
}