#include <iostream>
using namespace std;

void PrintLettersfromAtoZ()
{
	int upperlaettersinascii = 65;

	while (upperlaettersinascii <= 90)
	{
		cout << char(upperlaettersinascii) << endl;
		upperlaettersinascii++;
	}
}

int main()
{

	PrintLettersfromAtoZ();

	return 0;
}