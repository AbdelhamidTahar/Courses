#pragma warning (disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	//time_t is a data type used to store time in seconds
	time_t LocalTimeInSecondes;
	//The function time(0) returns the local date and time of the system as the number of seconds
	LocalTimeInSecondes = time(0);

	char *TimeInArrOfChar;
	//The function ctime converts time in seconds into a readable string in 
	// the form of an array of char.
	//	It takes the address of the time in seconds.
	//	It returns the address of the resulting string.
	TimeInArrOfChar = ctime(&LocalTimeInSecondes);
	cout << "Local date and time is: " << TimeInArrOfChar << endl;

	//tm is a data structure used to store time in an organized way,
	// such as hour, minute, second, day, month, and year.
	tm *GreenwichTimeInSecondes;


	//The function gmtime converts local time in seconds to Greenwich Mean Time.
	//It takes the address of the time in seconds.
	//It returns the address of the tm structure containing the date and time in GMT.
	GreenwichTimeInSecondes = gmtime(&LocalTimeInSecondes);


	//The function asctime converts Greenwich time stored in a tm structure into a readable array of char.
	//It takes the address of the structure.
	//It returns the address of the resulting char array.
	TimeInArrOfChar = asctime(GreenwichTimeInSecondes);
	cout << "Date and time in Greenwich Mean Time is: " << TimeInArrOfChar << endl;


	return 0;
}