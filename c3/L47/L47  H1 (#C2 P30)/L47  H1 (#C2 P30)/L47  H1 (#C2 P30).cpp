#include <iostream>
using namespace std;

void ReadNumber(int& Number)
{
	cout << "Please enter the number?" << endl;
	cin >> Number;
}

int CalculateFactorial(int Number)
{

	int sum = 1;

	for (Number; Number > 0; Number--)
	{
		sum = sum * Number;
	}

	return sum;

}

void PrintFactorial(int Number)
{
	cout << Number << endl;
}

int main()
{

	int Number;

	ReadNumber(Number);
	PrintFactorial( CalculateFactorial(Number) );

	return 0;
}