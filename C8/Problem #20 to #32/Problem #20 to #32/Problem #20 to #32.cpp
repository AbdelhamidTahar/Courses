// Problem #20, #21, #22, #32, #24, #25, #26, #27, #28, #29, #30.
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

struct stDate
{
	short Year;
	short Month;
	short Day;
};

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

bool IsFirstMonthInYear(short Month)
{
	return Month == 1;
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

stDate IncreaseDateByXDays(stDate Date, short NumberOfDays)
{
	for (short i = 1; i <= NumberOfDays; i++)
		Date = IncreaseDateByOneDay(Date);
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	short NumberOfDaysInMonth;

	Date.Day += 7;
	NumberOfDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInMonth)
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Year++;
			Date.Month = 1;
			Date.Day -= NumberOfDaysInMonth;
		}
		else
		{
			Date.Month++;
			Date.Day -= NumberOfDaysInMonth;
		}
	}

	return Date;

}

stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeks)
{
	for (short i = 1; i <= NumberOfWeeks; i++)
		Date = IncreaseDateByOneWeek(Date);
	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (IsLastMonthInYear(Date.Month))
	{
		if (IsLastDayInMonth(Date))
		{
			Date.Year++;
			Date.Month = 1;
			Date.Day = 31;
		}
		else
		{
			Date.Year++;
			Date.Month = 1;
		}
	}
	else if(IsFirstMonthInYear(Date.Month))
	{
		short MaxNumberOfdaysInMonth2 = NumberOfDaysInAMonth(2, Date.Year);
		if (Date.Day > MaxNumberOfdaysInMonth2)
		{
			Date.Month++;
			Date.Day = MaxNumberOfdaysInMonth2;
		}
		else
		{
			Date.Month++;
		}
	}
	else
	{
		if (IsLastDayInMonth(Date))
		{
			Date.Month++;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
		else
		{
			Date.Month++;
		}
	}
	return Date;
}


int main()
{
	stDate Date1;
	Date1 = ReadFullDate();

	Date1 = IncreaseDateByOneDay(Date1);
	printf("01-Adding One day is: %d/%d/%d", Date1.Day, Date1.Month, Date1.Year);



	return 0;
}