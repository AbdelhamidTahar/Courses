#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float numberofdays, numberofhours, numberofminutes, numberofseconds;

	cout << "Please enter  number of days?\n";
	cin >> numberofdays;

	cout << "Please enter the number of hours?\n";
	cin >> numberofhours;

	cout << "Please enter the number of minutes?\n";
	cin >> numberofminutes;

	cout << "Please enter the number of seconds?\n";
	cin >> numberofseconds;


	float totaloseconds;

	totaloseconds = (numberofdays * 24 * 60 * 60) + (numberofhours * 60 * 60) + (numberofminutes * 60) + numberofseconds;
	totaloseconds = round(totaloseconds);



	cout << totaloseconds << "\n";



	return 0;
}