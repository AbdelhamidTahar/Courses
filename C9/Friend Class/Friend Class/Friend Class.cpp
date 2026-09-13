#include <iostream>
using namespace std;

class clsA
{
private:
	int _VA1, _VA2, _VA3;
protected:
	float _VA4, _VA5, _VA6;
public:
	bool VA7, VA8, VA9;
	clsA()
	{
		_VA1 = 10;
		_VA2 = 10;
		_VA3 = 10 ;

		_VA4 = 20;
		_VA5 = 20;
		_VA6 = 20;

		VA7 = true;
		VA8 = true;
		VA9 = true;
	}

	void PrintPrivateclassAMembersInClassA()
	{
		cout << "Print Private class A Members In ClassA\n";
		cout << "_VA1: " << _VA1 << endl;
		cout << "_VA2: " << _VA2 << endl;
		cout << "_VA3: " << _VA3 << endl;
	}

	int VA1()
	{
		return _VA1;
	}

	friend class clsB;
};

class clsB 
{
private:
	int _VB1, _VB2, _VB3;
protected:
	float _VB4, _VB5, _VB6;
public:
	bool VB7, VB8, VB9;

	clsA b;

	clsB()
	{
		_VB1 = 00; _VB2 = 00; _VB3 = 00;
		_VB4 = 00; _VB5 = 00; _VB6 = 00;
		VB7 = 00; VB8 = 00; VB9 = 00;

		b._VA1 = 00;
		b._VA2 = 00;
		b._VA3 = 00;
		b._VA4 = 00;
		b._VA5 = 00;
		b._VA6 = 00;
	}

	void PrintPrivateclassBMembersInClassB()
	{
		cout << "Print Private class B Members In ClassB\n";
		cout << "_VB1: " << _VB1 << endl;
		cout << "_VB2: " << _VB2 << endl;
		cout << "_VB3: " << _VB3 << endl;
	}


	void PrintPrivateclassAMembersInClassA()
	{
		cout << "Print Private class A Members After Modifi In Class b\n";
		cout << "_VA1: " << b._VA1 << endl;
		cout << "_VA2: " << b._VA2 << endl;
		cout << "_VA3: " << b._VA3 << endl;
	}

};


int main()
{
	clsA ObjectA;
	


	ObjectA.PrintPrivateclassAMembersInClassA();


	clsB ObjectB;
	ObjectB.PrintPrivateclassBMembersInClassB();
	ObjectB.PrintPrivateclassAMembersInClassA();

	cout << ObjectA.VA1();



}