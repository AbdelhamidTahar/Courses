#include <iostream>
using namespace std;

struct personinformation
{
	unsigned short age;
	bool diverlicense;
}; 

void readpersoninformation(personinformation &info)
{
	cout << "please enter your age?" << endl;
	cin >> info.age;

	cout << "if you have driver licince ther 1 if not have enter 0" << endl;
	cin >> info.diverlicense;
}

bool chekjobrequirements(personinformation info)
{
	return  (info.age > 21 && info.diverlicense == true);
}

void printemploymentdecision(bool result)
{
	if (result == true)
	{
		cout << "HIRED" << endl;
	}
	else
	{
		cout << "REJECTED" << endl;
	}
}

int main()
{

	personinformation info;
	readpersoninformation(info);
	printemploymentdecision(chekjobrequirements(info));

	return 0;
}