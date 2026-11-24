#include <iostream>
using namespace std;

void readnumberofsales(unsigned int& totalsales)
{
	cout << "Please enter the number of sales you made?" << endl;
	cin >> totalsales;
}

unsigned int commissionratecalculation(unsigned int totalsales)
{
	if (totalsales >= 1000000)
	{
		return int(totalsales * 0.01);
	}
	else if (totalsales >= 500000)
	{
		return int(totalsales * 0.02);
	}
	else if (totalsales >= 100000)
	{
		return int(totalsales * 0.03);
	}
	else if (totalsales >= 50000)
	{
		return int(totalsales * 0.05);
	}
	else
	{
		return 0;
	}
}

void printtotalcomission(unsigned int totalcomission)
{
	cout << totalcomission << endl;
}

int main()
{

	unsigned int totalsales;

	readnumberofsales(totalsales);
	printtotalcomission( commissionratecalculation(totalsales) );

	return 0;
}