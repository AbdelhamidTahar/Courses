#include <iostream>
using namespace std;

void readage(unsigned short& age)
{
	cout << "Please enter your age?" << endl;
	cin >> age;
}

bool chekage(unsigned short age)
{
	return (age >= 18 && age <= 45);
}

void printresult(bool resultofcheck)
{
	if (resultofcheck == true)
	{
		cout << "VALID AGE" << endl;
	}
	else
	{
		cout << "INVALID AGE" << endl;
	}
}

int main()
{
	unsigned short age;

	readage(age);
	printresult(chekage(age));

	return 0;
}