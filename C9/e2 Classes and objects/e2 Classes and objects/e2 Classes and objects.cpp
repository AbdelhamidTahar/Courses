#include <iostream>
using namespace std;

class clsPerson
{
private:
	int _ID ;
	string _FirstName;
	string _LastName;
	string _FullName;
	short  _Age;
	bool   _Sex;
	bool   _IsLive;

public:

	void SetID()
	{
		static int Count = 0;
		_ID += Count;
	}
	int ID()
	{
		return _ID;
	}

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

	string FullName()
	{
		return _FirstName + _LastName;
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

	void SetIsLive(bool IsLive)
	{
		_IsLive = IsLive;
	}
	bool IsLive()
	{
		return _IsLive;
	}
};

int main()
{
	clsPerson Person1;
	Person1.SetID();
	Person1.SetFirstName("Abdelhamid");
	Person1.SetLastName("TAHAR");
	Person1.SetAge(24);
	Person1.SetSex(1);
	Person1.SetIsLive(1);

	cout << "First Name: " << Person1.FirstName() << endl;
	cout << "Last Name: " << Person1.LastName() << endl;
	cout << "Age: " << Person1.Age() << endl;
	cout << "Sex: " << Person1.Sex() << endl;
	cout << "Is Live: " << Person1.IsLive() << endl;

	return 0;
}