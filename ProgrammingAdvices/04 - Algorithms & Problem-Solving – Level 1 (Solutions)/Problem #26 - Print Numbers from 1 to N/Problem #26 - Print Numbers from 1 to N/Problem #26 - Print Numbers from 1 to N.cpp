#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please Enter A Namber ?" << endl;
	cin >> Number;

	return Number;
}

void PringRangeFrom1ToN_UsingWhileLoop(int N)
{

	cout << "Print Rang Using While Statment" << endl;

	int Counter = 0;

	while (Counter < N)
	{
		Counter++;
		cout << Counter << endl;
	}
}

void PringRangeFrom1ToN_UsingDoWhileLoop(int N)
{
	cout << "Print Rang Using Do While Statment" << endl;
	int Counter = 0;

	do {
		Counter++;
		cout << Counter << endl;
	} while (Counter < N);
}

void PringRangeFrom1ToN_UsingFoorLoop(int N)
{
	cout << "Print Rang Using Foor Statment" << endl;
	for (int Counter = 1; Counter <= N; Counter++)
	{
		cout << Counter << endl;
	}
}

int main()
{
	int N = ReadNumber();

	PringRangeFrom1ToN_UsingWhileLoop(N);
	PringRangeFrom1ToN_UsingDoWhileLoop(N);
	PringRangeFrom1ToN_UsingFoorLoop(N);

	return 0;
}