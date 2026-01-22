#include <iostream>
using namespace std;

int main()
{
	float billvalue;

	cout << "Please enter the BILL OF VALUE?\n";
	cin >> billvalue;

	float totalbill;

	totalbill = billvalue * 1.1;
	totalbill = totalbill * 1.16;

	cout << totalbill;

	return 0;
}