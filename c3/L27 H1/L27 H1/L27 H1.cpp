#include <iostream>
using namespace std;

struct person
{
	string name;
	unsigned short age;
	string city;
	string country;
	float Mothlysalary;
	char gender;
	bool ismarried;

};


int main()
{

	person person1;

	cout << "please enter your name? \n";
	cin >> person1.name;
	cout << "please enter your age? \n";
	cin >> person1.age;
	cout << "please enter your city? \n";
	cin >> person1.city;
	cout << "please enter your country? \n";
	cin >> person1.country;
	cout << "please enter your salary? \n";
	cin >> person1.Mothlysalary;
	cout << "please enter your gender? \n";
	cin >> person1.gender;
	cout << "are you married if yes enter 1 if no enter 0 ? \n";
	cin >> person1.ismarried;

	cout << "**********************************\n";
	cout << " Name : " << person1.name << "\n";
	cout << " Age : " << person1.age << "\n";
	cout << " City : " << person1. city << "\n";
		cout << " Country : " << person1.country << "\n";
	cout << " Monthly salary : " << person1.Mothlysalary << "\n";
	cout << " Yearly salary : " << person1.Mothlysalary * 12 << "\n";
	cout << " Gender : " << person1.gender << "\n";
	cout << " Married : " << person1.ismarried << "\n";
	cout << "**********************************\n";


	return 0;
}