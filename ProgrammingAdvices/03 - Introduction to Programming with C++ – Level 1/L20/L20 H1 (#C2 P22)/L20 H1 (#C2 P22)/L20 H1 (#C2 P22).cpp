#include <iostream>
using namespace std;

int main()
{

	float a, b;

	cout << "Please enter value of A \n";
	cin >> a;

	cout << "Please enter value of B \n";
	cin >> b;


	const float pi = 3.14; 
	float area;

	
	area = (pi * b * b / 4) * ((2 * a - b) / (2 * a + b));

	cout << area << "\n";



	return 0;
}
