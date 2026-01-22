#include <iostream>
using namespace std;

int main()
{
	int totalsecondes;
	
	cout << "Please enter the TOTAL OF SECONDES?\n";
	cin >> totalsecondes; 

	int secondesperday, secondesperhour, secondesperminute;

	secondesperday = 24 * 60 * 60;
	secondesperhour = 60 * 60;
	secondesperminute = 60; 

	int numberofdays , numberofhours , numberofminuts , numberofseconds , remainder ;

	numberofdays = floor (totalsecondes / secondesperday);
	remainder = totalsecondes % secondesperday;
	numberofhours = floor ( remainder / secondesperhour ) ;
	remainder = remainder % secondesperhour; 
	numberofminuts = floor(remainder / secondesperminute);
	numberofseconds = remainder % secondesperminute;

	cout << numberofdays << ":" << numberofhours << ":" << numberofminuts << ":" << numberofseconds; 


	return 0;
}