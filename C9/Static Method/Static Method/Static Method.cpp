#include <iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstNamr;
	string _LastName;
	short  _Age;
	bool   _Sex;
	bool   _IsLive;

public:
	static int Count;

	static int Func1()
	{
		return 99;
	}

	static float Func2()
	{
		return 99.99;
	}

	static bool Func3()
	{
		return true;
	}

	static string Func4()
	{
		return "Test";
	}

	static char Func5()
	{
		return 'P';
	}

	static void Func6()
	{
		cout << "yyy\n";
	}
};

int clsPerson::Count = 0;


int main()
{
	cout << clsPerson::Func1() << endl;
	cout << clsPerson::Func2() << endl;
	cout << clsPerson::Func3() << endl;
	cout << clsPerson::Func4() << endl;
	cout << clsPerson::Func5() << endl;
	clsPerson::Func6();



	clsPerson P1;
	cout << P1.Func1() << endl;
	cout << P1.Func2() << endl;
	cout << P1.Func3() << endl;
	cout << P1.Func4() << endl;
	cout << P1.Func5() << endl;
	P1.Func6();

	return 0;
}