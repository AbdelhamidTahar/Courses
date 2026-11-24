#include <iostream>
using namespace std;

void PrintUpperCharactar()
{
	cout << "*************************" << endl;
	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << endl;
	}
	cout << "*************************" << endl;
}

void PrintSmallCharactar()
{
	cout << "\n*************************" << endl;
	for (int i = 97; i <= 122; i++)
	{
		cout << char(i) << endl;
	}
	cout << "*************************" << endl;
}

int main()
{

	PrintUpperCharactar();
	PrintSmallCharactar();

	return 0;
}