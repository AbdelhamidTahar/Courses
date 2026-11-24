#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please Enter A number?" << endl;
	cin >> Number;

	return Number;
}

float CalculateHalfNumber(int Number)
{
	return float(Number) / 2;
}

void PrintResult(int Number)
{
	string Result = "Half Number of " + to_string(Number) + " is " + to_string(CalculateHalfNumber(Number));
	cout << Result << endl;
}

int main()
{
	PrintResult( ReadNumber() );

}