#pragma once

#include<iostream>
#include<cmath>
using namespace std;


namespace MathematicalOperations
{

    int SumNumbersThatHaveNoRemainderFrom1toN(int Number)

    {

        int Sum = 0;

        for (int i = 1; i < Number; i++)

        {

            if (Number % i == 0)

            {

                Sum += i;

            }

        }

        return Sum;

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

    void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }



}

namespace Lengths
{

    short LengthOfNumber(int Number)
    {
        short Count = 0;

        if (Number == 0)
        {
            return 1;
        }


        while (Number != 0)
        {
            Count++;
            Number = Number / 10;

        }

        return Count;
    }

}

namespace CheckNumber
{

    enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

    enPrimNotPrime CheckPrime(int Number)
    {
        int M = int( round(Number / 2));

        for (int Counter = 2; Counter <= M; Counter++)
        {
            if (Number % Counter == 0)
            {
                return enPrimNotPrime::NotPrime;
            }
        }

        return enPrimNotPrime::Prime;

    }

    //The function is very slow with large numbers. To improve it, click the following link:
    //https://gemini.google.com/share/40fc892491de
    bool isPerfectNumber(int Number)
    {
        int Sum = 0;

        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }

        return (Number == Sum);
    }

    bool IsOddNumber(int Number)
    {

        return (Number % 2 != 0);

    }

    bool IsEvenNumber(int Number)
    {

        return (Number % 2 == 0);

    }

    bool IsPalindromeNumber(int Number)
    {
        return Number == MathematicalOperations::ReverseNumber(Number);
    }


}

namespace Digits
{

    //This function calculates the number of times a given digit appears in a number
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

    //This function counts and prints the repetition frequency
    //of every digit from 1 to 9 within the input number.
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

    //Calculating the total number of digits
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



}

namespace OutPut
{

    void PrintPrimeNumbersFromNToN(int From, int To)
    {
        cout << "\n";
        cout << "Prime Numbers from " << From << " To " << To;
        cout << " are : " << endl;

        for (int i = From; i <= To; i++)
        {
            if (CheckNumber::CheckPrime(i) == CheckNumber::enPrimNotPrime::Prime)
            {

                cout << i << endl;
            }
        }
    }

    void PrintPrimeNumbersFrom1ToN(int Number)
    {
        PrintPrimeNumbersFromNToN(1, Number);
    }

    void PrintPerfectNumbersFromNToN(int From,int To)
    {
        for (int i = From; i <= To; i++)
        {
            if (CheckNumber::isPerfectNumber(i))
            {
                cout << i << endl;
            }
        }
    }

    void PrintPerfectNumbersFrom1ToN(int Number)
    {
        PrintPerfectNumbersFromNToN(1, Number);
    }


}