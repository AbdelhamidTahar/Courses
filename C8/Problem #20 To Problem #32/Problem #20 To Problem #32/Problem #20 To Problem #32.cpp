#include <iostream>
using namespace std;

struct clsDate
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
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :days[Month - 1];
}

bool IsLastDayInMonth(clsDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month,Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

clsDate DecreaseDateByOneDay(clsDate Date)
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

clsDate DecreaseDateByOneWeek(clsDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

clsDate DecreaseDateByOneMonth(clsDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	    //last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
		// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

clsDate DecreaseDateByXDays(short Days, clsDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

clsDate DecreaseDateByXMonths(short Months, clsDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

clsDate DecreaseDateByOneYear(clsDate Date)
{
	Date.Year++;
	return Date;
}

clsDate DecreaseDateByXYears(short Years, clsDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

clsDate DecreaseDateByXYearsFaster(short Years, clsDate Date)
{
	Date.Year += Years;
	return Date;
}

clsDate DecreaseDateByOneDecade(clsDate Date)
{
	//Period of 10 years
	Date.Year += 10;
	return Date;
}

clsDate DecreaseDateByXDecades(short Decade, clsDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

clsDate DecreaseDateByXDecadesFaster(short Decade, clsDate Date)
{
	Date.Year += Decade * 10;
	return Date;
}

clsDate DecreaseDateByOneCentury(clsDate Date)
{
	//Period of 100 years
	Date.Year += 100;
	return Date;
}

clsDate DecreaseDateByOneMillennium(clsDate Date)
{
	//Period of 1000 years
	Date.Year += 1000;
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

clsDate ReadFullDate()
{
	clsDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

int main()
{
	clsDate Date1 = ReadFullDate();
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