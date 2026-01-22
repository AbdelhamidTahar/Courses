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


float CalculateRemainder(float TotalBill ,float CashPiad)
{
	return CashPiad - TotalBill;
}



int main()
{
	float TotalBill = ReadPositiveNumber("Please enter Total Bill?");
	float CashPiad = ReadPositiveNumber("Please enter Cash Piad?");

	cout << endl << "Total Bill = " << TotalBill << endl;
	cout << endl << "Cash Piad = " << CashPiad << endl;

	cout << "***********************************\n" ;
	cout << "Remainder = " << CalculateRemainder(TotalBill, CashPiad);

	return 0;
}