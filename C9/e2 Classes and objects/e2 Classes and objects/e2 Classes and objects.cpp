#include <iostream>
using namespace std;

class clsPerson
{
private:

	int Var1 = 65;
	int Var2 = 66545;

	int PrivateFunc1()
	{ 
		return 100;
	}
	int PrivateFunc2()
	{
		return 100;
	}

protected:

	int PretectedFunc1()
	{
		return PrivateFunc2() + PrivateFunc1();
	}
	int PretectedFunc2()
	{
		return PrivateFunc1() + PrivateFunc2();
	}


public:
	string FirstName;
	string LastName;
	string FullName;
	short Age;
	short VarPerson = PretectedFunc2();
	string GetFullName()
	{
		return FirstName + " " + LastName;
	}
};

int main()
{
	clsPerson Person1;

	Person1.FirstName = "Abdelhamid";
	Person1.LastName = "TAHAR";
	Person1.Age = 24;
	Person1.FullName = Person1.GetFullName();

	return 0;
}