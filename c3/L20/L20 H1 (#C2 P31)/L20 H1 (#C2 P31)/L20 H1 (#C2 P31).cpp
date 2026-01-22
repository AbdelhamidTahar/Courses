#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "Please enter the number ?\n";
	cin >> num;

	int a, b, c;

	a = num * num;
	b = num * num * num;
	c = num * num * num * num ;

	cout << "\n";
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";


	return 0;
}