#include <iostream>
using namespace std;

enum enNymberType {Odd = 1 , Even = 2};

int ReadNumer()
{
	int Number;

	cout << "Please enter a number" << endl;
	cin >> Number; 

	return Number;
}

enNymberType CheckNumberType(int Number)
{
	int Result = Number % 2;

	if (Result == 0)
	{
		return enNymberType::Even;
	}
	else
	{
		return enNymberType::Odd;
	}
}

void PrintNumberType(enNymberType NumberType)
{
	if (NumberType == enNymberType::Even)
	{
		cout << "Number is Even" << endl;
	}
	else
	{
		cout << "Number is Odd" << endl;
	}
}

int main()
{

	PrintNumberType(CheckNumberType(ReadNumer()));

	return 0;
}