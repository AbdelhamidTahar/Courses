#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
	// ID is Read Only.
	int _ID;
	string _FirstName;
	string _LastName;
	string _FullName;
	short  _Age;
	bool   _Sex;
	bool   _IsLive;

public:
	// ID is Read Only.
	int GetID()
	{
		return _ID;
	}
	__declspec(property(get = GetID))int ID;


	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string GetFullName()
	{
		return _FirstName + _LastName;
	}

	void SetAge(string Age)
	{
		_Age = stoi(Age);
	}
	short GetAge()
	{
		return _Age;
	}
	__declspec(property(get = GetAge, put = SetAge)) short Age;

	void SetSex(bool Sex)
	{
		_Sex = Sex;
	}
	bool GetSex()
	{
		return _Sex;
	}
	__declspec(property(get = GetSex, put = SetSex))bool Sex;

	void SetIsLive(bool IsLive)
	{
		_IsLive = IsLive;
	}
	bool GetIsLive()
	{
		return _IsLive;
	}
	__declspec(property(get = GetIsLive, put = SetIsLive)) bool IsLive;
};

int main()
{
	clsPerson Person1;

	Person1.FirstName = "Abdelhamid";
	Person1.LastName = "TAHAR";
	Person1.Age = "24";
	Person1.Sex = 1;
	Person1.IsLive = 1;
	

	cout << "ID: " << Person1.ID << endl;
	cout << "First Name: " << Person1.FirstName << endl;
	cout << "Last Name: " << Person1.LastName << endl;
	cout << "Age: " << Person1.Age << endl;
	cout << "Sex: " << Person1.Sex << endl;
	cout << "Is Live: " << Person1.IsLive << endl;

	return 0;
}