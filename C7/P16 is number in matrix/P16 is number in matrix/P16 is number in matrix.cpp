#include <iostream>
#include <cstdio>
#include <cmath>
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

			arr[i][j] = Generates::RandomNumber(1,100);
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

bool IsNumberInMatrix(int Matrix[3][3],short Number, short Rows, short Cols)
{	
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number )
			{
				return true;
			}

			
		}

	}
	return false;

}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];


	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	short Number = User_Input::ReadPositiveNumber("\nPlease Enter The Number To Lock For In Matrix? ");

	if (IsNumberInMatrix(Matrix, Number, 3, 3))
	{
		cout << "Yes It's There.\n";
	}
	else
	{
		cout << "No It's Not There.\n";
	}



	return 0;
}