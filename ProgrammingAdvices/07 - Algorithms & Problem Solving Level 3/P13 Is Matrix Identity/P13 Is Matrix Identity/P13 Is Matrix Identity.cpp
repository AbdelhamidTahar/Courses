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

			arr[i][j] = Generates::RandomNumber(0,1);
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

bool IsMatrixIdentity(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != 1)
			{
				return false;
			}
			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;

}

int main()
{
	srand((unsigned)time(NULL));

	//int Matrix1[3][3];
	int Matrix1[3][3] = { {1,0,0}
						,{ 0,1,0 }
						,{ 0,0,1 } };


	//FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	


	if (IsMatrixIdentity(Matrix1, 3, 3))
		cout << "\nYES: Matrix Is Identity.\n";
	else
		cout << "\nNo: Matrix Is Not Identity.\n";






	return 0;
}