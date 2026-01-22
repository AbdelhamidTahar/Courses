#include <iostream>
using namespace std;

void readnumber(int &number)
{
	cout << "Please enter the number?" << endl;
	cin >> number;
}

void printnumbers(int number)
{
	for (int count = 1; count <= number; count++)
	{
		cout << count << endl;
	}
}

int main()
{
	int number;

	readnumber(number);
	printnumbers(number);

	return 0;
}
