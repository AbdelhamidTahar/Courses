#include <iostream>
using namespace std;

void ReadNumber(int& number)
{
	cout << "Please enter the number" << endl;
	cin >> number;
}

int SumEvenNumbers(int number)
{
	int sum = 0;
	for (int count = 1; count <= number; count++)
	{
		if (count % 2 == 0)
		{
			sum = sum + count;
		}
	}
	return sum;
}

void PrintSumEvenNumbers(int sum)
{
	cout << sum << endl;
}

int main()
{
	int number;

	ReadNumber(number);
	PrintSumEvenNumbers( SumEvenNumbers(number) );

	return 0;
}