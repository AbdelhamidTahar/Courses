#include <iostream>
using namespace std;

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{

	cout << "Please Enter Your Number 1 ?" << endl;
	cin >> Num1;

	cout << "Please Enter Your Number 2 ?" << endl;
	cin >> Num2;

	cout << "Please Enter Your Number 3 ?" << endl;
	cin >> Num3;
}

int SumOf3Numbers(int Num1, int Num2, int Num3)
{
	return Num1 + Num2 + Num3;
}

float CalculateAverage(int Num1, int Num2, int Num3)
{
	return (float)SumOf3Numbers(Num1, Num2, Num3) / 3;
}

void PrintResult(float Total)
{
	cout << "\nThe Total Sum Of Numbers Is: " << Total << endl;
}

int main()
{

	int Num1, Num2, Num3;

	ReadNumbers(Num1, Num2, Num3);
	PrintResult(CalculateAverage(Num1, Num2, Num3));

	return 0;
}