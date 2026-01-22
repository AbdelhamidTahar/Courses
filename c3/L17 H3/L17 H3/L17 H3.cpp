#include <iostream>
using namespace std;

int main()
{

	unsigned short age;
	cout << "Enter your age please: " << endl;

	cin >> age;
	unsigned short yourageafter5years = age + 5;

	cout << "After 5 years you will be " << yourageafter5years  << " years old." << endl;

	return 0;
}