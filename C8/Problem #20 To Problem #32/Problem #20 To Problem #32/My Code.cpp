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
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		Date.Day = 1;
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
	else if (IsFirstMonthInYear(Date.Month))
	{
		Date.Month++;
		short MaxNumberOfdaysInMonth2 = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > MaxNumberOfdaysInMonth2)
		{
			Date.Day = MaxNumberOfdaysInMonth2;
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

stDate IncreaseDateByXMonths(stDate Date, short NumberOfNonths)
{
	for (short i = 1; i <= NumberOfNonths; i++)
		Date = IncreaseDateByOneMonth(Date);
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{

	if (Date.Month == 2)
	{
		if (IsLastDayInMonth(Date))
		{
			Date.Year++;
			Date.Day = NumberOfDaysInAMonth(2, Date.Year);
			return Date;
		}	
	}
	Date.Year++;

	return Date;
}

stDate IncreaseDateByXYears(stDate Date, short NumberOfYears)
{
	for (short i = 1; i <= NumberOfYears; i++)
		Date = IncreaseDateByOneYear(Date);
	return Date;
}

enum eIncreaseDateType { eXYearsFaster = 1, eOneDecade = 2, eXDecadesFaster = 3, OneCentury = 4, eOneMillennium };

stDate HelpInMonth2(stDate Date, eIncreaseDateType IncreaseDateType, short NumberToAdd = 0)
{

		if (IsLastDayInMonth(Date))
		{
			switch (IncreaseDateType)
			{
			case IncreaseDateType::eXYearsFaster:
			{
				Date.Year += NumberToAdd;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				return Date;
			}
			case IncreaseDateType::eOneDecade:
			{
				Date.Year += 10;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				return Date;
			}
			case IncreaseDateType::eXDecadesFaster:
			{
				Date.Year += (NumberToAdd * 10);
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				return Date;
			}
			case IncreaseDateType::OneCentury:
			{
				Date.Year += 100;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				return Date;
			}
			case IncreaseDateType::eOneMillennium:
			{
				Date.Year += 1000;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				return Date;
			}
			}
		}
		else
		{
			switch (IncreaseDateType)
			{
			case IncreaseDateType::eXYearsFaster:
			{
				Date.Year += NumberToAdd;
				break;
			}
			case IncreaseDateType::eOneDecade:
			{
				Date.Year += 10;
				break;
			}
			case IncreaseDateType::eXDecadesFaster:
			{
				Date.Year += (NumberToAdd * 10);
				break;
			}
			case IncreaseDateType::OneCentury:
			{
				Date.Year += 100;
				break;
			}
			case IncreaseDateType::eOneMillennium:
			{
				Date.Year += 1000;
				break;
			}
			}
		}

		return Date;

}

stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYears)
{
	if (Date.Month == 2)
	{
		return HelpInMonth2(Date, eIncreaseDateType::eXYearsFaster, NumberOfYears);
	}
	Date.Year += NumberOfYears;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	if (Date.Month == 2)
	{
		return HelpInMonth2(Date, eIncreaseDateType::eOneDecade);
	}

	Date.Year += 10;
	return Date;

}

stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecades)
{
	for (short i = 1; i <= NumberOfDecades; i++)
		Date = IncreaseDateByOneDecade(Date);
	return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades)
{
	if (Date.Month == 2)
	{
		return HelpInMonth2(Date, eIncreaseDateType::eXDecadesFaster, NumberOfDecades);
	}
	Date.Year += (NumberOfDecades * 10);
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	if (Date.Month == 2)
	{
		return HelpInMonth2(Date, eIncreaseDateType::OneCentury);
	}
	Date.Year += 100;
	return Date;

}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	if (Date.Month == 2)
	{
		return HelpInMonth2(Date, eIncreaseDateType::OneMillennium);
	}
	Date.Year += 1000;
	return Date;

}


int main()
{
	stDate Date1;
	short HowManyAdd = 0;

	Date1 = ReadFullDate();

	cout << "\n\nDate After:\n\n";


	Date1 = IncreaseDateByOneDay(Date1);
	printf("01-Adding One day is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	HowManyAdd = 10;
	Date1 = IncreaseDateByXDays(Date1, HowManyAdd);
	printf("02-Adding %d days is: %d/%d/%d\n", HowManyAdd, Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneWeek(Date1);
	printf("03-Adding One Week is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByXWeeks(Date1, HowManyAdd);
	printf("04-Adding %d Weeks is: %d/%d/%d\n", HowManyAdd, Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByOneMonth(Date1);
	printf("05-Adding One Month is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	HowManyAdd = 5;
	Date1 = IncreaseDateByXMonths(Date1, HowManyAdd);
	printf("06-Adding %d Months is: %d/%d/%d\n", HowManyAdd, Date1.Day, Date1.Month, Date1.Year);



	Date1 = IncreaseDateByOneYear(Date1);
	printf("07-Adding One Year is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	HowManyAdd = 10;
	Date1 = IncreaseDateByXYears(Date1, HowManyAdd);
	printf("08-Adding %d Years is: %d/%d/%d\n", HowManyAdd, Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByXYearsFaster(Date1, HowManyAdd);
	printf("09-Adding %d Years (Faster) is: %d/%d/%d\n", HowManyAdd, Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByOneDecade(Date1);
	printf("10-Adding One Decade is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByXDecades(Date1, HowManyAdd);
	printf("11-Adding One Decades is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByXDecadesFaster(Date1, HowManyAdd);
	printf("12-Adding One Decades (Faster) is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByOneCentury(Date1);
	printf("13-Adding One Century is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByOneMillennium(Date1);
	printf("14-Adding One Millennium is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


	return 0;
}