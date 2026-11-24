#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float number , result ;

	cout << "Please enter the number?\n";
	cin >> number;

	result =round ( pow(number, 2) ); 
	cout << result << "\n";

	result = round ( pow(number, 3) );
	cout << result << "\n";

	result = round ( pow(number, 4) );
	cout << result << "\n";



	return 0;
}