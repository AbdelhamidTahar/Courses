#include <iostream>
using namespace std;

void print()
{
	
	for (int i = 10; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl; 
	}
}

int main()
{

	print();

	return 0;
}