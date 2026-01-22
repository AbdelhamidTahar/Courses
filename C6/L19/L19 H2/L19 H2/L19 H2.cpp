#include <iostream>
using namespace std;

int MyPow(int Base, int Power)
{
	if (Power == 0)
		return 1;

	return Base * MyPow( Base, Power - 1);
}


int main()
{
	cout << MyPow(3, 4);
}
