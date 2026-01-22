#pragma once

#include<iostream>
#include<string>
#include"MathLib.h"
#include"GenerateLib.h"
#include"InputLib.h"





namespace OperationsOnTheArray
{

    int SumArray(int arr[100], int arrLength);

    FindNumberPositionInArray(int Number, int arr[100], int arrLength);

    float ArrayAverage(int arr[100], int arrLength);

    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength);

    void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength);

    void AddArrayElement(int Number, int arr[100], int& arrLength);

    void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength);

    void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght);

    void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength);

    int EvenCount(int arr[100], int arrLength);

    int TimesRepeated(int Number, int arr[100], int arrLength);

    int MaxNumberInArray(int arr[100], int arrLength);

    int MinNumberInArray(int arr[100], int arrLength);

    int NegativerCount(int arr[100], int arrLength);

    int PositiverCount(int arr[100], int arrLength);

    int OddCount(int arr[100], int arrLength);

    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength);

    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength);

    ShuffleArray(int arr[100], int arrLength);

}
namespace ChickArray
{


    bool IsNumberInArray(int Number, int arr[100], int arrLength);

    bool IsPalindromeArray(int arr[100], int arrLength);


}
namespace Array_Input
{

    void ReadArray(int arr[100], int& arrLength);

    void FillArrayWith1toN(int arr[100], int arrLength);

    void InputUserNumbersInArray(int arr[100], int& arrLength);

    void FillArrayWithRandomNumbers(int arr[100], int& arrLength);

}
namespace Array_OutPut
{

    void PrintArray(int arr[100], int arrLength);

}



int OperationsOnTheArray::SumArray(int arr[100], int arrLength)
{
    int Sum = 0;

    for (int i = 0; i < arrLength; i++)
    {
        Sum += arr[i];
    }
    return Sum;
}

short OperationsOnTheArray::FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1;
}

float OperationsOnTheArray::ArrayAverage(int arr[100], int arrLength)
{
    return (float)SumArray(arr, arrLength) / arrLength;
}

void OperationsOnTheArray::CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
}

void OperationsOnTheArray::CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[arrLength - 1 - i];
}

void OperationsOnTheArray::AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void OperationsOnTheArray::CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arrSource[i] % 2 != 0)
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
    }
}

void OperationsOnTheArray::CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
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

void OperationsOnTheArray::CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckNumber::CheckPrime(arrSource[i]) == CheckNumber::enPrimNotPrime::Prime)
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
    }
}

int OperationsOnTheArray::EvenCount(int arr[100], int arrLength)
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

int OperationsOnTheArray::TimesRepeated(int Number, int arr[100], int arrLength)
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

int OperationsOnTheArray::MaxNumberInArray(int arr[100], int arrLength)
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

int OperationsOnTheArray::MinNumberInArray(int arr[100], int arrLength)
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

int OperationsOnTheArray::NegativerCount(int arr[100], int arrLength)
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

int OperationsOnTheArray::PositiverCount(int arr[100], int arrLength)
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

int OperationsOnTheArray::OddCount(int arr[100], int arrLength)
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

void OperationsOnTheArray::SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }
}

void OperationsOnTheArray::CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (FindNumberPositionInArray(arrSource[i], arrDestination, DestinationLength) == -1)
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

void OperationsOnTheArray::ShuffleArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        int index1 = Generates::RandomNumber(1, arrLength) - 1;
        int index2 = Generates::RandomNumber(1, arrLength) - 1;
        MathematicalOperations::Swap(arr[index1], arr[index2]);
    }
}




bool ChickArray::IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return OperationsOnTheArray::FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

bool ChickArray::IsPalindromeArray(int arr[100], int arrLength)
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



void Array_Input::ReadArray(int arr[100], int& arrLength)
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

void Array_Input::FillArrayWith1toN(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

void Array_Input::InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;
    do
    {

        OperationsOnTheArray::AddArrayElement(User_Input::ReadNumber(""), arr, arrLength);
        cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
        cin >> AddMore;

    } while (AddMore);
}

void Array_Input::FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = Generates::RandomNumber(1, 100);
}



void Array_OutPut::PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}