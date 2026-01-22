#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please Enter A Namber ?" << endl;
	cin >> Number;

	return Number;
}

void PringRangeFromNTo1_UsingWhileLoop(int N)
{

	cout << "Print Rang Using While Statment" << endl;

	int Counter = N + 1;

	while (Counter > 1)
	{
		Counter--;
		cout << Counter << endl;
	}
	
}

void PringRangeFromNTo1_UsingDoWhileLoop(int N)
{
	cout << "Print Rang Using Do While Statment" << endl;

	int Counter = N + 1;

	do {
		Counter--;
		cout << Counter << endl;
	}while(Counter > 1);
	
}

void PringRangeFromNTo1_UsingFoorLoop(int N)
{
	cout << "Print Rang Using Foor Statment" << endl;
	for (int Counter = N; Counter >=1; Counter--)
	{
		cout << Counter << endl;
	}
	
}

int main()
{
	int N = ReadNumber();

	PringRangeFromNTo1_UsingWhileLoop(N);
	PringRangeFromNTo1_UsingDoWhileLoop(N);
	PringRangeFromNTo1_UsingFoorLoop(N);

	return 0;
}