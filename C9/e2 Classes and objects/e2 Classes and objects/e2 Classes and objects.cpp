#include <iostream>
using namespace std;

class clsPerson
{
	bool IsLive;

public:

	short Age;
	bool Sex;
	string FirstName;
	string LastName;
	string FullName()
	{
		return FirstName + " " + LastName;
	}
	void PrintPersonInfo()
	{
		cout << "FullName: " << FullName() << endl;
		cout << "Age: " << Age << endl;
		cout << "Sex: " << Sex << endl;
		cout << "Is Live: " << IsLive << endl;
	}

};

int main()
{

	clsPerson Person1;

	Person1.FirstName = "Abdelhamid";
	Person1.LastName = "TAHAR";
	Person1.Age = 24;
	Person1.Sex = 1;
	Person1.PrintPersonInfo();


	return 0;
}