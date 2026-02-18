#include <iostream>
#include <cstdio>
//#include <iomanip>
#include "GenerateLib.h"

using namespace std;

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			arr[i][j] = Generates::RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d \t", 2, arr[i][j]);
		}
		cout << endl;
	}
}

void PrintMiddleRow(int arr[3][3], short Rows, short Cols)
{

	int MiddleRow = Rows / 2;
	for (short j = 0; j < Cols; j++)
	{
		
		
			printf("%0*d \t", 2, arr[MiddleRow][j]);
		
		
	}
	cout << "\n";
}

void PrintMiddleCol(int arr[3][3], short Rows, short Cols)
{
	int MiddleCol = Cols / 2;
	for (short j = 0; j < Rows; j++)
	{


		printf("%0*d \t", 2, arr[j][MiddleCol]);


	}
	cout << "\n";
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(arr, 3, 3);

	
	cout << "\nMiddle Row Of Matrix1 is:\n";
	PrintMiddleRow(arr,3,3);

	cout << "\nMiddle Col Of Matrix1 is:\n";
	PrintMiddleCol(arr,3,3);
	return 0;
}