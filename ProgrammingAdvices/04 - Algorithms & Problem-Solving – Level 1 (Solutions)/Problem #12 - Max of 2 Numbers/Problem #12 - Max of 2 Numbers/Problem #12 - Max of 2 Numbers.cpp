#include <iostream>
using namespace std;

void ReadNumbers(int& Num1, int& Num2)
{
	cout << "Please Enter The Number 1?" << endl;
	cin >> Num1;

	cout << "Please Enter The Number 2?" << endl;
	cin >> Num2;
}

int MaxOfNumbers(int Num1, int Num2)
{
	if (Num1 > Num2)
		return Num1;
	else
		return Num2;
}

void PrintResult(int Max)
{
	cout << "\nThe Maximum Number Is: " << Max << endl;
}

int main()
{

	int Num1, Num2;

	ReadNumbers(Num1, Num2);
	PrintResult(MaxOfNumbers(Num1, Num2));

	return 0;
}