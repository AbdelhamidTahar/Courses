#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float r ,area;
	const float pi = 3.14159;

	cout << "please enter the value of R?\n";
	cin >> r;

	area = pi * pow(r, 2);
	area = ceil(area);

	cout << area << endl;



	return 0;
}