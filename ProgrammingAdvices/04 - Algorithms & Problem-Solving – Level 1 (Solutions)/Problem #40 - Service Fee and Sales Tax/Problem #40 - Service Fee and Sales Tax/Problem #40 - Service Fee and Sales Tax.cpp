#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

float TotalBillAfterServiceAndTax(float TotalBill)
{

	TotalBill *= 1.1;
	TotalBill *= 1.16;

	return TotalBill;
}

int main()
{

	float TotalBill = ReadPositiveNumber("Please Enter Total Bill?");

	cout << endl;

	cout << "Total Bill = " << TotalBill << endl;

	cout << "Total Bill After Service and Tax = "
		<< TotalBillAfterServiceAndTax(TotalBill) << endl;

	return 0;
}