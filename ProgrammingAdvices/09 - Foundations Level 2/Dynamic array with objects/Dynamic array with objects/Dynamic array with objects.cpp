#include <iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;

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


	clsPerson(string FirstName, string LastName)
	{
		_FirstName = FirstName;
		_LastName = LastName;
	}

	clsPerson()
	{

	}

};

int main()
{
	int NumberOfObjects = 100;
	clsPerson* ObjectsArray = new clsPerson[NumberOfObjects];


	for (int i = 0; i < NumberOfObjects; i++)
	{
		ObjectsArray[i] = clsPerson("Test", "Test");

	}

	for (int i = 0; i < NumberOfObjects; i++)
	{
		cout << ObjectsArray[i].FirstName()
			<< ObjectsArray[i].LastName() << endl;
	}

	delete []ObjectsArray;
	return 0;
}