#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a Year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{

	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == 
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == 
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
};


int main()
{

	stDate Date1, Date2;
	Date1 = ReadFullDate();
	Date2 = ReadFullDate();

	if (IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is Less then Date2";
	}
	else
	{
		cout << "\nNo, Date1 is Not Less then Date2";
	}

	return 0;
}