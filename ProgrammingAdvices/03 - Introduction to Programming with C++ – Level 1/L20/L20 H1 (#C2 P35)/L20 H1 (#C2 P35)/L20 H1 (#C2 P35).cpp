#include <iostream>
using namespace std;

int main()
{

	int pennies , nickels, dimes, quarters, dollars ;

	cout << "Plese enter how mush do you have pennies: \n";
	cin >> pennies;

	cout << "Plese enter how mush do you have nickels: \n";
	cin >> nickels;

	cout << "Plese enter how mush do you have dimes: \n";
	cin >> dimes;

	cout << "Plese enter how mush do you have quarters: \n";
	cin >> quarters;

	cout << "Plese enter how mush do you have dollars: \n";
	cin >> dollars;


	float totalpennies;
	totalpennies = pennies * 1 + nickels * 5 + dimes * 10 + quarters * 25 + dollars * 100;

	float totaldollars;
	totaldollars = totalpennies / 100;

	cout <<"\n" << totalpennies << " pennies\n";
	cout << totaldollars << " dollars\n";






	return 0;
}