#include<iostream>
using namespace std;

struct strPiggyBankContent
{
	int Pennies, Nickels, Dimes, Quarters, Dollars;
};

strPiggyBankContent ReadPiggyBankContent()
{
	strPiggyBankContent PiggyBankContent;

	cout << "Please Enter A Total Pennies?" << endl;
	cin >> PiggyBankContent.Pennies;

	cout << "Please Enter A Total Nickels?" << endl;
	cin >> PiggyBankContent.Nickels;

	cout << "Please Enter A Total Dimes?" << endl;
	cin >> PiggyBankContent.Dimes;

	cout << "Please Enter A Total Quarters?" << endl;
	cin >> PiggyBankContent.Quarters;

	cout << "Please Enter A Total Dollars?" << endl;
	cin >> PiggyBankContent.Dollars;

	return PiggyBankContent;
}

int CalculateTotalPennies(strPiggyBankContent PiggyBankContent)
{
	int TotalPennies = 0;
	
	TotalPennies = PiggyBankContent.Pennies * 1 + PiggyBankContent.Nickels * 5 + PiggyBankContent.Dimes * 10
		+ PiggyBankContent.Quarters * 25 + PiggyBankContent.Dollars * 100;

	return TotalPennies;
}

int main()
{
	int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());
	cout << "Total Pennies = " << TotalPennies << endl;
	cout << "Total Dollars = " << (float)TotalPennies /100 << endl;

	return 0;
}
