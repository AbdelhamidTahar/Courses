#include <iostream>
using namespace std;

int main()
{

	float number1, number2;

	cout << "Please enter the number 1 ?\n";
	cin >> number1;

	cout << "Please enter the number 2 ?\n";
	cin >> number2 ;
	
	cout << "\n";
	cout << number1 << "\n";
	cout << number2 << "\n\n";

	float temp;
	
	temp = number1;
	number1 = number2;
	number2 = temp;

	cout << number1 << "\n";
	cout << number2 << "\n";

	return 0;
}