#include <iostream>
using namespace std;

struct stratmaccount
{
	unsigned int pin;
	float balance = 7500;
};

void readpin(stratmaccount &accountperson)
{
	cout << "Please enter your ATM PIN?" << endl;
	cin >> accountperson.pin;
}

bool checkpincode(stratmaccount  accountperson)
{
	unsigned int rigthpincode = 1234;


	return (accountperson.pin == rigthpincode);
}

void printpalance(bool checkpincode , stratmaccount accountperson)
{
	if (checkpincode == true)
	{
		cout << "Your balance is: " << accountperson.balance  << endl; 
	}
	else
	{
		cout << "Wrong PIN" << endl;
	}
}


int main()
{
	stratmaccount accountperson;

	readpin(accountperson);
	printpalance( checkpincode(accountperson) , accountperson);


	return 0;
}