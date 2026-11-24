#include <iostream>
using namespace std; 

int main()
{

	int numberofdays, numberofhours, numberofminutes, numberofseconds;

	cout << "Please enter the number of DAYS?\n";
	cin >> numberofdays;

	cout << "Please enter the number of HOURS?\n";
	cin >> numberofhours;
	
	cout << "Please enter the number of MINUTS?\n";
	cin >> numberofminutes;

	cout << "Please enter the number of SECONDS?\n";
	cin >> numberofseconds;

	int totalseconds = (numberofdays * 24 * 60 * 60) + (numberofhours * 60 * 60) + (numberofminutes * 60) + numberofseconds;

	cout << totalseconds << " SECONDES\n";

	return 0;
}