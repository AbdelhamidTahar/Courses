#include <iostream>
using namespace std;

void ReadNumber(int &Number)
{
	cout << "Please enter a number\n";
	cin >> Number;
}

int SumEvenNumbersfrom1toN(int Number)
{
	int Sum = 0;
	while (Number >= 1)
	{
		if (Number % 2 == 0)
		{
			Sum += Number;
		}
		Number--;
	}
	return Sum;
}

void PrintSumEvenNumbers(int Sum)
{
	cout << Sum << endl;
}

int main()
{

	int Number;
	ReadNumber(Number);
	PrintSumEvenNumbers( SumEvenNumbersfrom1toN(Number) );

	return 0;
}