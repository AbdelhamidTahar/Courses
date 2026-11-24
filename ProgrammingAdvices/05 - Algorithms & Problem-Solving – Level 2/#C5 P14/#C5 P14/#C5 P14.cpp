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

void PrintInvertedLetterPattern(int Number)
{
    cout << "\n"; 

    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
        {
            cout << char(i);  
        }

        cout << "\n";  
    }
}

int main()
{

    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positeve number?"));

    return 0;
}