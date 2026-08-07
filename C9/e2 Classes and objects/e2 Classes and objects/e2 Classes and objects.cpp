#include <iostream>
using namespace std;

// Any thing in class is Member.
// We Have 2 Type of Members.
//Data Member
//Member Func(Method)
class clsPerson
{
	//Data Member
	bool IsLive;

public:

	//Data Member
	short Age;
	//Data Member
	bool Sex;
	//Data Member
	string FirstName;
	//Data Member
	string LastName;
	//Data Member

	//Member Func
	string FullName()
	{
		return FirstName + " " + LastName;
	}
	//Member Func
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