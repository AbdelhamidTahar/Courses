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

int SumOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			Sum += Matrix[i][j];
		}
	}
	return Sum;
}

bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
		
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];


	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
	{
		cout << "\nYes: Matrices Are Equal \n";
	}
	else
	{
		cout << "\nNo: Matrices Are Not Equal \n";
	}


	


	return 0;
}