#include <iostream>
#include <iomanip>
#include "GenerateLib.h"
using namespace std;

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i< Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = Generates::RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i< Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
	int Sum = 0;
	for (short i = 0; i < Rows;i++)
	{
		Sum += arr[i][ColNumber];
	}

	return Sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe Following Are The Sum Of Each Col In The Matrix: \n";

	for (short j = 0; j < Rows; j++)
	{
		cout << "Col " << j+1 << " Sum: " << ColSum(arr, Rows, j) << "\n";
	}
	cout << endl;
}

int main()
{
   
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);
	PrintEachColSum(arr, 3, 3);

}
