#include <iostream>
using namespace std;

int main()
{

	float totalbill, cashpaid; 

	cout << "Please enter the TOTAL BILL?\n";
	cin >> totalbill;

	cout << "Please enter the CASH PAID?\n";
	cin >> cashpaid;

	float remainder;

	remainder = cashpaid - totalbill;
	

	cout << "\n" << remainder;


	return 0;
}