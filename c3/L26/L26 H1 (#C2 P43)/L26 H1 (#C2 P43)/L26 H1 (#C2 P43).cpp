#include <iostream>
#include <cmath>
using namespace std; 

int main()
{
	unsigned int totalseconds;

	cout << "please enter the total seconds?\n";
	cin >> totalseconds; 

	unsigned int secondsperdey, secondsperhour, secondsperminute;

	secondsperdey = 24 * 60 * 60;
	secondsperhour = 60 * 60;
	secondsperminute = 60;

	unsigned int numberofdays, numberofhours, numberofminutes, numberofseconds, reminder;
	
	numberofdays = round(totalseconds / secondsperdey);
	reminder = totalseconds % secondsperdey;

	numberofhours = round(reminder / secondsperhour);
	reminder = reminder % secondsperhour;

	numberofminutes = round(reminder / secondsperminute);
	reminder = reminder % secondsperminute;

	numberofseconds =  reminder ; 

	cout << numberofdays << ":" << numberofhours << ":" << numberofminutes << ":" << numberofseconds;

	return 0; 
}