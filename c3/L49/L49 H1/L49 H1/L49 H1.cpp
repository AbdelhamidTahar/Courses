#include <iostream>
using namespace std; 

void print()
{
	for (int i = 65; i <= 90; i++)
	{
		cout << "Letter:" << char(i) << "\n";
		for (int j = 65; j <= 90; j++)
		{
			cout << char(i) << char(j) << "\n";
		}
		cout << "----------------------------" << endl;
	}
}

int main()
{

	print();

	return 0; 
}