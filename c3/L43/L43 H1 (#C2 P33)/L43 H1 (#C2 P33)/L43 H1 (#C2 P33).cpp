#include <iostream>
using namespace std;

void readgrade(float& grade)
{
	cout << "Please enter your grade" << endl;
	cin >> grade;
}

void result(float grade)
{
	if (grade >= 90)
	{
		cout << "A" << endl;
	}
	else if (grade >= 80)
	{
		cout << "B" << endl;
	}
	else if (grade >= 70)
	{
		cout << "C" << endl;
	}
	else if (grade >= 60)
	{
		cout << "D" << endl;
	}
	else if (grade >= 50)
	{
		cout << "E" << endl;
	}
	else
	{
		cout << "F" << endl;
	}
}

int main()
{

	float grade;

	readgrade(grade);
	result(grade);

	return 0;
}