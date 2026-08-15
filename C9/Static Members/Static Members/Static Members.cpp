#include <iostream>
using namespace std;

class clsTest
{
	static int y;
public:
	clsTest()
	{
		b++;
	}

	int a = 0;
	static int b;


	void Print()
	{
		cout << "Value Of Var:  " << a << endl;
		cout << "Static Of Var: " << b << endl;
		cout << "Static y: " << y << endl;
	}

};
int clsTest::y = 8;
int clsTest::b = 0;

 

int main()
{
	clsTest o1, o2, o3, o4;

	o1.a = 14;
	o2.a = 14;
	o3.a = 14;
	o4.a = 14;
	
	clsTest::b = 66;
	

	o1.Print() ;
	o2.Print() ;
	o3.Print() ;
	o4.Print() ;

	
	o1.b = 99;

	o1.Print();
	o2.Print();
	o3.Print();
	o4.Print();

	return 0;
}