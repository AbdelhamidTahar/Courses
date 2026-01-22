#include <iostream>
#include <cmath>

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);


	return Number;
}

enPrimNotPrime CheckPrime(int Number)
{
	

	if (Number < 2)
		return enPrimNotPrime::NotPrime;

	int M = round(Number / 2);

	for (int Count = 2; Count <= M ; Count++)
	{
		if (Number % Count == 0)
		{
			return  enPrimNotPrime::NotPrime;
			
		}
		
	}
	return enPrimNotPrime::Prime;
}

void PrintNumberType(int Number)
{

	

	switch (CheckPrime(Number))
	{
	case enPrimNotPrime::Prime:
		cout << "The Number Is Prime";
		break;
	case enPrimNotPrime::NotPrime:
		cout << "The Number Is Not Prime";
		break;
	}
}

int main()
{

	PrintNumberType(ReadPositiveNumber("Please enter a positive number"));
	
	return 0;
}