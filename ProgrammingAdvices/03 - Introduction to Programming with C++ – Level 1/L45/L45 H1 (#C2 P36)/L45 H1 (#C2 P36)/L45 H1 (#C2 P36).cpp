#include <iostream>
using namespace std;

struct calculationinformation
{
	float number1;
	float number2;
	char operationtype;
};

void readoperationinformation(calculationinformation& Operationinformation)
{
	cout << "Please enter the first number" << endl;
	cin >> Operationinformation.number1;

	cout << "Please enter the seconde number" << endl;
	cin >> Operationinformation.number2;

	cout << "Please enter the operation type" << endl;
	cin >> Operationinformation.operationtype;
}

float calculate(calculationinformation Operationinformation)
{
	switch (Operationinformation.operationtype)
	{
	case('+'):
		return Operationinformation.number1 + Operationinformation.number2;
		break;
	case ('-'):
		return Operationinformation.number1 - Operationinformation.number2;
		break;
	case ('*'):
		return Operationinformation.number1 * Operationinformation.number2;
		break;
	case ('/'):
		return Operationinformation.number1 / Operationinformation.number2;
		break;
	default:
		return 0;
	}

}

void printresult(float result)
{
	cout << result << endl;
}

int main()
{
	calculationinformation strOperationinformation;

	readoperationinformation(strOperationinformation);
	printresult(calculate(strOperationinformation));

	return 0;
}