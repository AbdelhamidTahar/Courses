#include <iostream>
using namespace std;

class clsA
{
private:
	int _V1;
protected:
	int _V2;
public:
	int V3;
	
	clsA()
	{
		_V1 = 10;
		_V2 = 20;
		V3 = 30;
	}

	friend int Sum(clsA ObjectA);
};


int Sum(clsA ObjectA)
{
	return ObjectA._V1 + ObjectA._V2 + ObjectA.V3;
}


int main()
{
	clsA A;

	cout << Sum(A);

	return 0;
}
