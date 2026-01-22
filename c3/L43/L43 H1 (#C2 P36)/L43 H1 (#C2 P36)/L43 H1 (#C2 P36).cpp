#include <iostream>
using namespace std;

struct strcalculationinformation
{
	float number1;
	float number2;
	char operationtype;
};

void readnumber(float &number)
{
	cin >> number;
}

void readnumbers(strcalculationinformation& numbers)
{
	cout << "Please enter the first number?" << endl;
	readnumber(numbers.number1);
	cout << "Please enter the second number?" << endl;
	readnumber(numbers.number2);
}

void readoperationtype(strcalculationinformation& operationtype)
{
	cout << "Please enter operation type" << endl;
	cin >> operationtype.operationtype;
}

float calcul(strcalculationinformation operationinfo)
{
	if (operationinfo.operationtype == '+')
	{
		return operationinfo.number1 + operationinfo.number2;
	}
	else if (operationinfo.operationtype == '-')
	{
		return operationinfo.number1 - operationinfo.number2;
	}
	else if (operationinfo.operationtype == '*')
	{
		return operationinfo.number1 * operationinfo.number2;
	}
	else if (operationinfo.operationtype == '/')
	{
		return operationinfo.number1 / operationinfo.number2;
	}
	else 
	{
		return 0;
	}
}

void printresult(float result)
{
	cout << result << endl;
}

int main()
{

	strcalculationinformation operationinfo;

	readnumbers(operationinfo);
	readoperationtype(operationinfo);
	printresult(calcul(operationinfo));
	
	return 0;
}