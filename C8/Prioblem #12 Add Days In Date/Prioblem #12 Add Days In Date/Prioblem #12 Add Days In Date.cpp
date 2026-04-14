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


struct sDate
{
	short Year;
	short Month;
	short Day;
};


sDate AddDaysToDAte(short AddDays, sDate Date)
{
	short MaxDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	for (int i = 1; i <= AddDays; i++)
	{
		if (Date.Day != MaxDaysInMonth)
		{
			Date.Day++;
		}
		else
		{
			if (Date.Month == 12)
			{
				Date.Year++;
				Date.Month = 1;
				Date.Day = 1;
				MaxDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
			else
			{
				Date.Month++;
				MaxDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
				Date.Day = 1;
			}
		}
		
	}
	return Date;
}

int main()
{
	sDate Date;

	 Date.Day = ReadDay();
	 Date.Month = ReadMonth();
	 Date.Year = ReadYear();
   	 short AddDays ;
	 cout << "\nHow Many Days To Add? ";
	 cin >> AddDays;
	 Date = AddDaysToDAte(AddDays, Date);
	 cout << "Date After Adding [" << AddDays << "] days is : " << Date.Day << '/' << Date.Month << '/' << Date.Year;

	

	system("pause>0");
	return 0;
}