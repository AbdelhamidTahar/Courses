#include <iostream>
using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;

	cout << "Please Enter A Namber ?" << endl;
	cin >> Number;

	return Number;
}

enOddOrEven CheckOddOrEven(int Counter)
{
	if (Counter % 2 != 0)
		return enOddOrEven::Odd;
	else
		return enOddOrEven::Even;
}

void SumEvenNumbersfrom1toN_UsingWhileLoop(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "Sum Odd Number Using While Statment" << endl;
	while (Counter < N)
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;

	}

	cout << Sum << endl;
}

void SumOddNumbersfrom1toN_UsingDoWhileLoop(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "Sum Odd Number Using Do While Statment" << endl;
	do {
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;

	} while (Counter < N);
	
	cout << Sum << endl;
}

void SumOddNumbersfrom1toN_UsingFoorLoop(int N)
{
	int Sum = 0;

	cout << "Sum Odd Number Using Foor Statment" << endl;
	for (int Counter = 1; Counter <= N; Counter++)
	{

		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;

	}
	
	cout << Sum << endl;
}

int main()
{
	int N = ReadNumber();

	SumEvenNumbersfrom1toN_UsingWhileLoop(N);
	SumOddNumbersfrom1toN_UsingDoWhileLoop(N);
    SumOddNumbersfrom1toN_UsingFoorLoop(N);

	return 0;
}