#include <iostream>
using namespace std;

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month to check? ";
	cin >> Month;
	return Month;
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth (short Month,short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	if (Month == 2)
	{
		return isLeapYear(Year) ? 29 : 28;
	}
	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}
	//if you reach here then its 30 days.
	return 30;

}

short NumberOfHoursInMonth(short Month,short Year)
{

	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month,short Year)
{

	return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(short Month,short Year)
{

	return NumberOfMinutesInMonth(Month, Year) * 60;
}

void PrintCertainMonth    (short Month,short Year)
{
	cout << "\n\n";
	cout << "Number Of Days    in Year [" << Month << "] is " << NumberOfDaysInMonth   (Month,Year) << endl;
	cout << "Number Of Hours   in Year [" << Month << "] is " << NumberOfHoursInMonth  (Month,Year) << endl;
	cout << "Number Of Minutes in Year [" << Month << "] is " << NumberOfMinutesInMonth(Month,Year) << endl;
	cout << "Number Of Seconds in Year [" << Month << "] is " << NumberOfSecondsInMonth(Month,Year) << endl;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	PrintCertainMonth(Month,Year);
	system("pause>0");


	return 0;
}