#include <iostream>
using namespace std;

void ReadNumber(int& Number)
{

	cout << "Please enter a Number?" << endl;
	cin >> Number;

}

void PrintNumbersfrom1toN(int Number)
{
	int i = 1;
	while (i <= Number)
	{
		cout << i << endl;
		i++;
	}
}

int main()
{

	int Number;

	ReadNumber(Number);
	PrintNumbersfrom1toN(Number);


	return 0;
}