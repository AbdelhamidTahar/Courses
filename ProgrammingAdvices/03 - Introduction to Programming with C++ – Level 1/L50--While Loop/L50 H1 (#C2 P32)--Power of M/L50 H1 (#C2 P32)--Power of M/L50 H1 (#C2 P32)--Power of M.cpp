#include <iostream>
using namespace std;

void ReadNumber(int& Number)
{
	cout << "Please enter the Number" << endl;
	cin >> Number;
}

void ReadPower(int &M)
{
	cout << "Please enter M" << endl;
	cin >> M;
}

int PowerofM(int Number, int M)
{
	int Sum = 1;

	while (M > 0)
	{
		Sum *= Number;
		M--;
	}

	return Sum; 
}

void PrintPowerofM(int Number, int M)
{
	cout << PowerofM(Number, M) << endl;
}

int main()
{

	int Number, M;

	ReadNumber(Number);
	ReadPower(M);
	PrintPowerofM(Number , M );

	return 0;
}