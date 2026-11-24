#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

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

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate DecreaseDateByOneDay(stDate Date)
{

	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
			Date.Day = 31;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	else
		Date.Day--;

	return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Year--;
		Date.Month = 12;
	}
	else
	{
		Date.Month--;
		short NumberOfDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		Date.Day = (Date.Day > NumberOfDays) ? NumberOfDays : Date.Day;
	}


	return Date;
}

stDate DecreaseDateByXMonths(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	if (Date.Month == 2)
	{
		short NumberOfdays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		Date.Day = (Date.Day > NumberOfdays) ? NumberOfdays : Date.Day;
	}

	return Date;
}

stDate DecreaseDateByXYears(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year -= Years;
	if (Date.Month == 2)
	{
		short NumberOfdays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		Date.Day = (Date.Day > NumberOfdays) ? NumberOfdays : Date.Day;
	}

	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{

	Date.Year -= 10;
	if (Date.Month == 2)
	{
		short NumberOfdays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		Date.Day = (Date.Day > NumberOfdays) ? NumberOfdays : Date.Day;
	}

	return Date;
}

stDate DecreaseDateByXDecades(short Decade, stDate Date)
{
	for (short i = 1; i <= Decade; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year -= Decade * 10;
	if (Date.Month == 2)
	{
		short NumberOfdays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		Date.Day = (Date.Day > NumberOfdays) ? NumberOfdays : Date.Day;
	}

	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{

	Date.Year -= 100;
	if (Date.Month == 2)
	{
		short NumberOfdays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		Date.Day = (Date.Day > NumberOfdays) ? NumberOfdays : Date.Day;
	}

	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	if (Date.Month == 2)
	{
		short NumberOfdays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		Date.Day = (Date.Day > NumberOfdays) ? NumberOfdays : Date.Day;
	}

	return Date;
}

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
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
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

int main()
{
	stDate Date1 = ReadFullDate();
	cout << "\nDate After: \n";
	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Substracting one day is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = DecreaseDateByXDays(10, Date1);
	cout << "\n02-Substracting 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Substracting one week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeeks(10, Date1);
	cout << "\n04-Substracting 10 weeks is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Substracting one month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonths(5, Date1);
	cout << "\n06-Substracting 5 months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Substracting one year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYears(10, Date1);
	cout << "\n08-Substracting 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Substracting 10 Years (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Substracting one Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecades(10, Date1);
	cout << "\n11-Substracting 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Substracting 10 Decade (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Substracting One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Substracting One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");

	return 0;
}