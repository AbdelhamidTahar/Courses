#include <iostream>
using namespace std;

int ReadTotalSales()
{
	int TotalSales;

	cout << "Please Enter Total Sales " << endl;
	cin >> TotalSales;

	return TotalSales;

}

float GettCommissionPercentage(int TotalSales)
{
	if (TotalSales >= 1000000)
		return 0.01;
	else if (TotalSales >= 500000)
		return 0.02;
	else if (TotalSales >= 100000)
		return 0.03;
	else if (TotalSales >= 500000)
		return 0.05;
	else
		return 0.00;
}

float CalculateTotalCommission(int TotalSales)
{
	
		return GettCommissionPercentage(TotalSales) * TotalSales;
}

int main()
{
	int TotalSales = ReadTotalSales();

	cout << "Commission Percentage = " << GettCommissionPercentage(TotalSales);
	cout << "Total Commission = " << CalculateTotalCommission(TotalSales);


	return 0;
}