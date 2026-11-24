#include <iostream>
using namespace std;

void ReadNUmber(int &Number)
{

	cout << "Please enter a number" << endl;
	cin >> Number;

}

void PrintNumbersfromNto1(int Number)
{
	while (Number >= 1)
	{
		cout << Number << endl;
		Number--;
	}
}

int main()
{

	int Number;
	ReadNUmber(Number);
	PrintNumbersfromNto1(Number);


	return 0;
}