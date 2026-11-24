#include <iostream>
using namespace std;

void ReadNumber(int& Number)
{
	cout << "Please enter a number\n";
	cin >> Number;
}

bool VirifidNumber(int Number)
{
	if (Number != -99)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int SumUntil(int &Number)
{
	int Sum = 0;
	while(VirifidNumber(Number) == true )
	{
		Sum += Number;
		ReadNumber(Number);
	}
	return Sum;
}

void PrintSumUntil(int Sum)
{
	cout << Sum << endl;
}


int main()
{

	int Number;

	ReadNumber(Number);
	PrintSumUntil( SumUntil(Number) );


	return 0;
}