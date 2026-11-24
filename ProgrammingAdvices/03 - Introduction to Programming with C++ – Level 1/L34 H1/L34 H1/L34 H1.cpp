#include <iostream>
using namespace std;

void my_sum_Procedures()
{
	int number1, number2;

	cout << "Please enter the number1\n";
	cin >> number1;
	cout << "\n";

	cout << "Enter the number2\n";
	cin >> number2;

	cout << "*********************\n";
	cout << number1 + number2 << endl;

}


int my_sum_Functions()
{
	int number1, number2;

	cout << "Please enter the number1\n";
	cin >> number1;
	cout << "\n";

	cout << "Enter the number2\n";
	cin >> number2;

	cout << "*********************\n";
	return number1 + number2;

}


int main()
{

	my_sum_Procedures();
	cout << my_sum_Functions()<< endl;

	return 0;
}