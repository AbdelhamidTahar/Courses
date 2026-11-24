#include <iostream>
using namespace std;

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year)
{
	
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{

	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{

	return NumberOfMinutesInYear(Year) * 60;
}

void PrintCertainYear(short Year)
{
	cout << "\n\n";
	cout << "Number Of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year) << endl;
	cout << "Number Of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear(Year) << endl;
	cout << "Number Of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year) << endl;
	cout << "Number Of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year) << endl;
}

int main()
{
	short Year = ReadYear();
	PrintCertainYear(Year);
	system("pause>0");


	return 0;
}