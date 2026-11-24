#include<iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	short _Age;
	bool _Sex;

public:

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string FirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string LastName()
	{
		return _LastName;
	}

	void SetAge(short Age)
	{
		_Age = Age;
	}
	short Age()
	{
		return _Age;
	}

	void SetSex(bool Sex)
	{
		_Sex = Sex;
	}
	bool Sex()
	{
		return _Sex;
	}

	clsPerson(string FirstName,string LastName, short Age, bool Sex)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Age = Age;
		_Sex = Sex;

	}

	static void Print(clsPerson *Person)
	{
		cout << "Full Name: " << Person->FirstName() + " " + Person->LastName() << endl;
		cout << "Age      : " <<  Person->Age()<< endl;
		cout << "Age      : " <<  Person->Sex() << endl;

	}


};

int main()
{

	clsPerson P1("ABDELHAMID","TAHAR",24,1);


	P1.Print(&P1);



	return 0;
}