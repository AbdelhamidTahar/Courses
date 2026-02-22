#include <iostream>
#include <cstdio>
//#include <iomanip>
#include "GenerateLib.h"
#include "InputLib.h"

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

short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
	short count = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0 ; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				count++;
			}
		}
		
	}
	return count;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];


	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	int Number = 0;
	Number = User_Input::ReadPositiveNumber("\nEnter The Number To Count In Matrix? ");

	cout << "\nNumber " << Number << "Count In Matrix Is: " << CountNumberInMatrix(Matrix, Number, 3, 3);




	return 0;
}