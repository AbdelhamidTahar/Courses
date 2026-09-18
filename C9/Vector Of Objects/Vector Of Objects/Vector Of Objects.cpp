#include <iostream>
#include <vector>
using namespace std;

class clsTest
{
private:
	int x;
public:
	clsTest(int x)
	{
		this->x = x;
	}

	clsTest(const clsTest &Copy)
	{
		x = Copy.x;
	}

	int X()
	{
		return x;
	}
};

int main()
{
	vector<clsTest> vObjects;
	int NumberOfObjects = 10;
	
	for (int i = 0; i <= NumberOfObjects; i++)
	{

		vObjects.push_back(clsTest(i));
	
	}

for (int i = 0; i <= NumberOfObjects; i++)
{
	cout << vObjects[i].X() << endl;
}


	return 0;
}