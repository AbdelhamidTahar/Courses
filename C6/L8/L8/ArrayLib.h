#pragma once

#include<iostream>
#include<string>
#include"MathLib.h"
#include"GenerateLib.h"
#include"InputLib.h"



namespace OperationsOnTheArray
{

    int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;

        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        return Sum;
    }

    short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i;
        }
        return -1;
    }

    float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }

    void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }

    void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
        arrLength++;
        arr[arrLength - 1] = Number;
    }

    void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arrSource[i] % 2 != 0)
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (CheckNumber::CheckPrime(arrSource[i]) == CheckNumber::enPrimNotPrime::Prime)
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;
            }
        }

        arr2Lenght = --Counter;
    }

    void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (CheckNumber::CheckPrime(arrSource[i]) == CheckNumber::enPrimNotPrime::Prime)
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int count = 0;
        for (int i = 0; i <= arrLength - 1; i++)
        {
            if (Number == arr[i])
            {
                count++;
            }
        }
        return count;
    }

    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;
    }

    int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = 0;
        Min = arr[0];

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;
    }

    int NegativerCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    int PositiverCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }

    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if ( FindNumberPositionInArray(arrSource[i], arrDestination, DestinationLength) == -1)
            {
                AddArrayElement(arrSource[i], arrDestination, DestinationLength);
            }
        }
    }

    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            int index1 = Generates::RandomNumber(1, arrLength) - 1;
            int index2 = Generates::RandomNumber(1, arrLength) - 1;
            MathematicalOperations::Swap(arr[index1], arr[index2]);
        }
    }

}

namespace ChickArray
{


    bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return OperationsOnTheArray::FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }

    bool IsPalindromeArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength / 2; i++)
        {
            if (arr[i] != arr[arrLength - i - 1])
            {
                return false;
            }
        }
        return true;
    }


}

namespace Array_Input
{

    void ReadArray(int arr[100], int& arrLength)
    {

        arrLength = 0;

        do
        {

            arrLength = User_Input::ReadNumber("\nEnter number of elements:");


        } while (arrLength <= 0);


        string Message = "";
        cout << "\nEnter array elements: \n";

        for (int i = 0; i < arrLength; i++)
        {

             Message = "Element [" + to_string(i + 1) + "] : ";
             arr[i] = User_Input::ReadNumber(Message);
                
        }
        cout << endl;
    }

    void FillArrayWith1toN(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }

    void InputUserNumbersInArray(int arr[100], int& arrLength)
    {
        bool AddMore = true;
        do
        {

            OperationsOnTheArray::AddArrayElement(User_Input::ReadNumber(""), arr, arrLength);
            cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
            cin >> AddMore;

        } while (AddMore);
    }

    void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;

        for (int i = 0; i < arrLength; i++)
            arr[i] = Generates::RandomNumber(1, 100);
    }

}

namespace Array_OutPut
{

    void PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";

        cout << "\n";
    }

}

