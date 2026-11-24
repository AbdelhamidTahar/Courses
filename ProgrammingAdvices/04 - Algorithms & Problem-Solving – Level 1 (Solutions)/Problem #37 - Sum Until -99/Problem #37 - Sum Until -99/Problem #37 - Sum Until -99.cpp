#include <iostream>
#include <string>

using namespace std;

float ReadNumber(string Message)
{
	float Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

int SumNumbers()
{
	int Sum = 0;
	int Number = 0;
	int Counter = 1;

	do {

		Number = ReadNumber("Please enter number " + to_string(Counter));

		if (Number == -99)
		{
			break;
		}

		Sum += Number;
		Counter++;

	} while (Number != -99);

	return Sum;

}

int main()
{
	cout << endl << "Result = " << SumNumbers() << endl;

	return 0;
}