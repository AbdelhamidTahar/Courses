#include <iostream>
using namespace std;

class clsA
{
private:
	int x;
	void Func1()
	{

	}

protected:

	int y;
	void Func2()
	{

	}

public:
	void Func3()
	{

	}
};

class clsB : public clsA
{
public:
	int z;
	void Func6()
	{

	}
};

int main()
{
	clsB B;

	B.Func3();
}