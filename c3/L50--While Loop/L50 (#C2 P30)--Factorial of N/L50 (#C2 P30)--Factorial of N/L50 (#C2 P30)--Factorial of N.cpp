#include <iostream>
using namespace std;

void ReadNumber(int &Number)
{

	cout << "Please enter a number?\n";
	cin >> Number;
}

bool ValidatePositiveNumber(int Number)
{
	if (Number >= 1)
	{
		return true;
	}
	return false;
}

int SumFactorialofNumber(bool ValidNumber , int &Number)
{
	while (ValidNumber == false)
	{

		cout << "Wrong Number" << endl;
		ReadNumber(Number);

	}

	int Sum = 1;

	while (Number >= 1)
	{
		Sum *= Number;
		Number--;
	}


	return Sum;
}

void PrintSumFactorialofNumber(int Sum)
{
	cout << Sum << endl;
}

int main()
{

	int Number;
	ReadNumber(Number);
	PrintSumFactorialofNumber(SumFactorialofNumber(ValidatePositiveNumber(Number), Number));


	return 0;
}