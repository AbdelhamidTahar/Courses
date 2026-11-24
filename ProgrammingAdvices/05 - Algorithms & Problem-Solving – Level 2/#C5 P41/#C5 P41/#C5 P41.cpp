#include <iostream>
#include <cmath>

using namespace std;


void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 10;
    arr[4] = 50;
    arr[5] = 50;
    arr[6] = 10;
    arr[7] = 10;
    arr[8] = 10;
    arr[9] = 10;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

bool IsPalindromeArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[arrLength - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[100], arrLength = 0;


    FillArray(arr, arrLength);

    cout << "\nArray elementes:\n";
    PrintArray(arr, arrLength);

    if (IsPalindromeArray(arr, arrLength))
    {
        cout << "\nYes Array Is Palindrome\n";
    }
    else
    {
        cout << "\nNo Array Is Not Palindrome\n";
    }

}
