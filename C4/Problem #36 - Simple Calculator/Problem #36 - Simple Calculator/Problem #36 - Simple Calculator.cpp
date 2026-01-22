#include <iostream>
using namespace std;

enum enOperationType{Add='+',Subtract='-',Muliply='*',Divide='/' };

float ReadNumber(string Message)
{
	float Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

enOperationType ReadType()
{
	char To = '+';
	cout << "Please enter Operation Type ( +, - , * , / )?\n";
	cin >> To;

	return (enOperationType)To;
}

float Calculate(float Number1, float Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Subtract:
		return Number1 - Number2;
	case enOperationType::Muliply:
		return Number1 * Number2;
	case enOperationType::Divide:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

int main()
{

	float Number1 = ReadNumber("Please Enter The First Number");
	float Number2 = ReadNumber("Please Enter The Second Number");
	enOperationType OpType = ReadType();

	cout << endl << "Result = " << Calculate(Number1, Number2, OpType);

	



	return 0;
}