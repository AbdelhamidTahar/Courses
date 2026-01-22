#include<iostream>
#include <cmath>
using namespace std;

enum enPrimNotPrime {Prime=1,NotPrime=2};

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

enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
        {
            return enPrimNotPrime::NotPrime;
        }
    }

    return enPrimNotPrime::Prime;

}

void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\n";  
    cout << "Prime Numbers from " << 1 << " To " << Number;
    cout << " are : " << endl;

    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimNotPrime::Prime)
        {

            cout << i << endl;
        }
    }
}

int main()
{

    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please Reade Positive Number?"));

    return 0;
}