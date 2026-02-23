#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include "GenerateLib.h"


using namespace std;

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			arr[i][j] = Generates::RandomNumber(1, 100);
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

//bool IsRowPalindrome(int Matrix[3][3], short Row, short Cols)
//{
//	short HalfLength = Cols / 2;
//	for (short j = 0; j < HalfLength; j++)
//	{
//		if (Matrix[Row][j] != Matrix[Row][Cols - j - 1])
//		{
//			return false;
//		}
//	}
//	return true;
//}

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
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

	int Matrix[3][3] = { {1,2,1},{32,3,32},{44,5,44} };

	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	
	if (IsPalindromeMatrix(Matrix, 3, 3))
	{
		cout << "\nYes: Matrix Is Palindrome.\n";
	}
	else
	{
		cout << "\nNo: Matrix Is Palindrome.\n";
	}



	return 0;
}