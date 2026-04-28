#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	short a, y, m;
	a = (14 - Date.Month) / 12;
	y = Date.Year - a;
	m = Date.Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetNameOfDayInDate(stDate Date)
{
	string DayName [] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DayName[DayOfWeekOrder(Date)];
}

bool IsEndOfWeek(stDate Date)
{
	return (DayOfWeekOrder(Date) == 6) ? true : false;
}

bool IsWeekEnd(stDate Date)
{
	short IndexDay = DayOfWeekOrder(Date);
	return ((IndexDay == 6) || (IndexDay == 5)) ? true : false;
}

bool IsBusinessDay(stDate Date)
{
	return (IsWeekEnd(Date) == false);
}

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

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

short DaysUnitilTheEndOfWeek(stDate Date)
{
	short IndexDay = DayOfWeekOrder(Date);
	short Count = 0;

	while (IndexDay != 6)
	{
		Date = IncreaseDateByOneDay(Date);
		Count++;
		IndexDay = DayOfWeekOrder(Date);
	}
	return Count;
}

short DaysUnitilTheEndOfMonth(stDate Date)
{
	short NumberOfDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
	short Count = 0;

	while (Date.Day < NumberOfDays)
	{
		Date = IncreaseDateByOneDay(Date);
		Count++;
	}
	return Count;
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

short DaysUnitilTheEndOfYear(stDate Date)
{
	short NumberOfDayInYears = (isLeapYear(Date.Year)) ? 366 : 365;
	return NumberOfDayInYears - NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
}


int main()
{
	stDate Date = GetSystemDate();

	cout << "Today is " << GetNameOfDayInDate(Date) 
		<< ", " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n\n";

	cout << "Is it End of Week?\n";
	if(IsEndOfWeek(Date))
		cout << "Yes it is End Of Week.\n\n";
	else
		cout << "No Not End Of Week.\n\n";


	cout << "Is it Week End?\n";
	if (IsWeekEnd(Date))
		cout << "Yes it is a Week End.\n\n";
	else
		cout << "No Not a Week End.\n\n";



	cout << "Is it Business Day?\n";
	if (IsBusinessDay(Date))
		cout << "Yes it is a Business Day.\n\n";
	else
		cout << "No Not a Business Day.\n\n";


	cout << "Days until end of week : " << DaysUnitilTheEndOfWeek(Date) << " Day(s).\n";
	cout << "Days until end of Month : " << DaysUnitilTheEndOfMonth(Date) << " Day(s).\n";
	cout << "Days until end of Year : " << DaysUnitilTheEndOfYear(Date) << " Day(s).\n";

	return 0;
}