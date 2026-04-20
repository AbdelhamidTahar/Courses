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

struct stDate
{
	short Year;
	short Month;
	short Day;
};

int CalculateDifferenceDaysIntwoDates(stDate Date1, stDate Date2, bool IncludingEndDays = false)
{
	short DaysInDate1 = NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
	short DaysInDate2 = NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year);
	
	return (DaysInDate1 < DaysInDate2) ? ((IncludingEndDays == false) ? DaysInDate2 - DaysInDate1 : DaysInDate2 + 1 - DaysInDate1) : -1;

}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}


int main()
{
	stDate Date1, Date2;
	Date1 = ReadFullDate();
	Date2 = ReadFullDate();

	printf("Difference is : %d  Day(s).\n", CalculateDifferenceDaysIntwoDates(Date1,Date2));
	printf("Difference (Including End Day) is : %d  Day(s).\n", CalculateDifferenceDaysIntwoDates(Date1, Date2,true));

	return 0;
}