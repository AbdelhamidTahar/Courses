#include <iostream>
using namespace std;

int main()
{
	string name;
	unsigned short age;
	string city;
	string country;
	float monthly_salary;
	char gender;
	bool is_married;


	cout << "Enter your name please?" << endl;
	cin >> name;

	cout << "Enter your age please?" << endl;
	cin >> age;
	
	cout << "Enter your city please?" << endl;
	cin >> city;

	cout << "Enter your country please?" << endl;
	cin >> country;
	
	cout << "Enter your monthly salary?" << endl;
	cin >> monthly_salary;

	cout << "Enter your gender M/F please?" << endl;
	cin >> gender ;
	
	cout << "If you married? enter \'TRUE or 1\' otherwase enter \'FALSE or 0\': " << endl;
	cin >> is_married;



	cout << "***************************" << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << " Years." << endl;
	cout << "City: " << city << endl;
	cout << "Country: " << country << endl;
	cout << "Monthly salary: " << monthly_salary << endl;
	cout << "Yearly salary: " << monthly_salary * 12 << endl;
	cout << "Gender: " << gender << endl;
	cout << "Married: " << is_married << endl;
	cout << "***************************" << endl;

	return 0;
}