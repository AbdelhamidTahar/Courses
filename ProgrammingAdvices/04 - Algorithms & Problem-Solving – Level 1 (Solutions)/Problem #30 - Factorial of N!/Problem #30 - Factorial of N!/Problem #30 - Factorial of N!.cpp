#include <iostream>
using namespace std;

int ReadAPositiveNumber(string Message)
{
	int Number;

	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);

	return Number;
}

int Factorial(int N)
{
	int F = 1;

	for (int Counter = N; Counter >= 1; Counter--)
	{
		F *= Counter;
	}
	return F;
}

//int Factorial_UsingWhileLoop(int N)
//{
//	int F = 1;
//	int Counter = N + 1;
//
//	while (Counter > 1)
//	{
//		Counter--;
//		F *= Counter;
//	}
//
//	return F;
//}
//
//int Factorial_UsingDoWhileLoop(int N)
//{
//	int F = 1;
//	int Counter = N + 1;
//
//	do {
//		Counter--;
//		F *= Counter;
//	} while (Counter > 1);
//
//	return F;
//}

int main()
{

	cout << Factorial(ReadAPositiveNumber("Please Enter A Positive Number"));

	return 0;
}