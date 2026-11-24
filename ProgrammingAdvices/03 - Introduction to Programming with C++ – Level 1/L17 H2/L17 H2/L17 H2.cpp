#include <iostream>
using namespace std;

int main()
{

	int number1, number2, number3;

	cout << "Enter the first number: " << endl;
	cin >> number1;

	cout << "Enter the secend number: " << endl;
	cin >> number2;

	cout << "Enter the third number: " << endl ;
	cin >> number3;

	int sum_of_numbers = number1 + number2 + number3;
	
	cout << endl ;
	cout << number1 << " +" << endl ;
	cout << number2 << " +" << endl ;
	cout << number3 << endl ;
	cout << "-------------------" << endl;
	cout  << sum_of_numbers << endl;

	return 0;
}