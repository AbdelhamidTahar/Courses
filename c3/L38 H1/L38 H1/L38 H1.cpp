#include <iostream>
#include<string>
using namespace std;

struct strinfo
{
	
	string full_name;
	unsigned short age;
	string city;
	string country;
	float monthly_salary;
	char gender;
	bool is_married;
};

void readinfo(strinfo &info)
{

	cout << "PLease enter your FULL NAME? "<< endl;
	getline(cin, info.full_name);

	cout << "PLease enter your AGE?" << endl;
	cin >> info.age;

	cout << "PLease enter your CITY?" << endl;
	cin >> info.city;

	cout << "PLease enter your COUNTRY?" << endl;
	cin >> info.country;

	cout << "PLease enter your MONTHLY SALARY?" << endl;
	cin >> info.monthly_salary;

	cout << "PLease enter your GENDER M/F?" << endl;
	cin >> info.gender;

	cout << "PLease if you married enter 1  if you not married ehter 0?" << endl;
	cin >> info.is_married;
}


void printinfo(strinfo info)
{
	cout << "\n" << "******************************\n";
	cout << "Name: " << info.full_name << "\n";
	cout << "Age: " << info.age << "\n";
	cout << "City: " << info.city << "\n";
	cout << "Monthy salary: " << info.monthly_salary << "\n";
	cout << "Yearly salary: " << info.monthly_salary*12 << "\n";
	cout << "Gender: " << info.gender << "\n";
	cout << "Married: " << info.is_married <<"\n";
	cout << "\n" << "******************************" << endl;

}


int main()
{
	strinfo person1info;
	readinfo(person1info);
	printinfo(person1info);

	return 0;
}