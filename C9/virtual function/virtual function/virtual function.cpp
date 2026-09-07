#include <iostream>
using namespace std;

class clsPerson
{
public:
	virtual void Print()
	{
		cout << "HI I'M A PERSON. \n";
	}
};

class clsStudent:public clsPerson
{
public:
    void Print()
	{
		cout << "HI I'M A STUDENT. \n";
	}
};

class clsEmpleey :public clsPerson
{
public:
    void Print()
	{
		cout << "HI I'M A Empleey. \n";
	}
};


int main()
{
	clsPerson Person;
	clsStudent Student;
	clsEmpleey Empleey;



	clsPerson* PTRPerson1 = &Student;
	PTRPerson1->Print();

	clsPerson* PTRPerson2 = &Empleey;
	PTRPerson2->Print();



	return 0;
}