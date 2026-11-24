#include <iostream>
using namespace std;

void ReadNumber(int& number)
{
	cout << "Please enter the number?" << endl;
	cin >> number;
}

int SumOddNumbers(int number)
{
	int sum = 0;
	for (int count = 1; count <= number; count++)
	{
		if (count % 2 != 0)
		{
			sum = sum + count;
		}
		else;
	}
	return sum;
}

void PrintSumOddNumbers(int result)
{
	cout << result << endl;
}

int main()
{
	int number;

	ReadNumber(number);
	PrintSumOddNumbers( SumOddNumbers(number) );


	return 0;
}