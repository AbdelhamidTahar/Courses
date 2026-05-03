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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month ==
		Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
		: false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum eDateComparisonResult { Befor = -1, Equal = 0, After = 1 };

eDateComparisonResult compareTwoDates(stDate Date1, stDate Date2)
{
	return IsDate1BeforeDate2(Date1, Date2) ? eDateComparisonResult::Befor 
		: (IsDate1EqualDate2(Date1, Date2) ? eDateComparisonResult::Equal : eDateComparisonResult::After);
}

int main()
{

	stDate Date1, Date2;
	Date1 = ReadFullDate();
	Date2 = ReadFullDate();

	cout << "Compare Result = " << compareTwoDates(Date1, Date2);

	return 0;
}