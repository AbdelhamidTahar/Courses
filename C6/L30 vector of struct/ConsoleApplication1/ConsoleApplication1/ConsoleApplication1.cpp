#include<iostream>
#include<vector>
using namespace std;

struct stEmployee
{
	string FirstName = "";
	string LastName = "";
	float Salary = 0;
};

void ReadEmployees(vector <stEmployee> &vEmployees)
{
	stEmployee TempEmployee;
	char AddMoreEmployee = 'Y';

	while (AddMoreEmployee == 'Y' || AddMoreEmployee == 'y')
	{
		cout << "Enter First Name: ";
		cin >> TempEmployee.FirstName;
		cout << "Enter Last Name: ";
		cin >> TempEmployee.LastName;
		cout << "Enter Salary: ";
		cin >> TempEmployee.Salary;
		vEmployees.push_back(TempEmployee);

		cout << "\nDo You Want Add More Employee ?  Y/N:";
		cin >> AddMoreEmployee;

	}


}

void PrintEmployees(vector <stEmployee>& vEmployees)
{

	cout << "\nEmployees:\n\n";
	for (stEmployee &Employee : vEmployees)
	{
		cout << "First Name: " << Employee.FirstName << endl;
		cout << "Last Name : " << Employee.LastName << endl;
		cout << "Salary    : " << Employee.Salary << endl;
		cout << endl;
	}


}

int main()
{

	vector <stEmployee> vEmployees;

	ReadEmployees(vEmployees);
	PrintEmployees(vEmployees);

	return 0;
}