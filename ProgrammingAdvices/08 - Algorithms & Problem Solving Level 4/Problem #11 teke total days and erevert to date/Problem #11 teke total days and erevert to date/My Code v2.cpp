#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}

short NumberOfMonthInTotalDays(short TotalDays, short Year)
{

	short NumberdayInMonth;
	short Month = 0;

	for (short i = 1; i <= 12; i++)
	{
		NumberdayInMonth = NumberOfDaysInAMonth(i, Year);

		if ((TotalDays -= NumberdayInMonth) >= 0)
		{

			Month += 1;
		}
		else
		{
			Month += 1;
			break;
		}
	}
	return Month;
}

short NumberOfDayInMonthTotalDays(short TotalDays, short Month, short Year)
{

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays -= NumberOfDaysInAMonth(i, Year);
	}

	return TotalDays;
}


int main()
{
	short Year, Month, Day, TotalDays;

	Day = ReadDay();
	Month = ReadMonth();
	Year = ReadYear();
	TotalDays = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
	cout << "\nNumber Of Days From Begining Of The Year is " << TotalDays << endl;

	short ConvertDaysToMonth = NumberOfMonthInTotalDays(TotalDays, Year);
	short ConvertDaysToDay = NumberOfDayInMonthTotalDays(TotalDays, ConvertDaysToMonth, Year);

	cout << "Date For[" << TotalDays << "] is : "
		<< ConvertDaysToDay
		<< "/" << ConvertDaysToMonth
		<< "/" << Year;



	system("pause>0");
	return 0;
}