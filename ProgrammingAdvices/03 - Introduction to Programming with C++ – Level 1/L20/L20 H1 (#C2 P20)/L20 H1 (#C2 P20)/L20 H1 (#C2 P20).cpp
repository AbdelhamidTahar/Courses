#include <iostream>
using namespace std;

int main()
{

	float a;

	cout << "Please enter value of A \n";
	cin >> a;

	const float pi = 3.14;
	float area;

	
	area = (pi * (a * a)) / 4;

	cout << area << "\n";



	return 0;
}
