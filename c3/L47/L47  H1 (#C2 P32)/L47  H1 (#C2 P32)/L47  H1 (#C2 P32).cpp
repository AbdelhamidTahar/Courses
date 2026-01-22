#include <iostream>
using namespace std;

void ReadNumber(int& Number)
{

	cout << "Please enter the number?" << endl;
	cin >> Number;

}

void ReadPower(int& Power)
{

	cout << "Please enter the power?" << endl;
	cin >> Power;

}

int NumberPowerM(int Number, int Power)
{
	if (Power == 0)
	{
		return 1;
	}
	else
	{
		int Sum = 1;
		for (int Count = 1; Count <= Power; Count++)
		{
			Sum = Sum * Number;
		}
		return Sum;
	}

}

void PrintResultNumberPowerM(int result)
{
	cout << result << endl;
}



int main()
{

	int Number, Power;

	ReadNumber(Number);
	ReadPower(Power);
	PrintResultNumberPowerM( NumberPowerM(Number, Power) );

	return 0;

}