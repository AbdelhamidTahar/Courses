#include <iostream>
#include <iomanip>
#include "GenerateLib.h"
using namespace std;

void FillMatrixWithRandomNumber(int arr[3][3], short NumberOfRows, short NumberOfColumns)
{
	for (short i = 0; i< NumberOfRows; i++)
	{
		for (short j = 0; j < NumberOfColumns; j++)
		{
			arr[i][j] = Generates::RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short NumberOfRows, short NumberOfColumns)
{
	cout << "The Following is a 3x3 Random Matrix\n";
	for (short i = 0; i< NumberOfRows; i++)
	{
		for (short j = 0; j < NumberOfColumns; j++)
		{
			cout << setw(3) << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int SumOfmatrixColumn(int arr[3][3], short NumberOfRows, short ColumnNumber)
{
	int Sum = 0;
	for (short i = 0; i < NumberOfRows;i++)
	{
		Sum += arr[i][ColumnNumber];
	}

	return Sum;
}

void PrintSumOfEachColumn(int arr[3][3], short NumberOfRows, short NumberOfColumns)
{
	cout << "\nThe Following Are The Sum Of Each Col In The Matrix: \n";
	for (short j = 0; j < NumberOfColumns; j++)
	{
		cout << "Col " << j+1 << " Sum: " << SumOfmatrixColumn(arr, NumberOfRows, j) << "\n";
	}
	cout << endl;
}

int main()
{
   
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixWithRandomNumber(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	PrintSumOfEachColumn(arr, 3, 3);

}
