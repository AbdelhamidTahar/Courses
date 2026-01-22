#include <iostream>
using namespace std;

int main()
{
	float loanamount, monthlyinstallment;

	cout << "PLease enter tne LOAN AMOUNT do you need?\n";
	cin  >> loanamount;

	cout << "Please enter the MONTHLY INSTALLMENT?\n";
	cin >> monthlyinstallment;

	float totalmothe;
	totalmothe = loanamount / monthlyinstallment;

	cout << totalmothe << "\n";

	return 0;
}