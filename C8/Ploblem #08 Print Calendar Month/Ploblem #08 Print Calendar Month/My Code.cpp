#include <iostream>
#include <iomanip>
using namespace std;

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month to check? ";
	cin >> Month;
	return Month;
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	short NumberOfDays[12] = { 31, 28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

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

string MonthShortName(short Month)
{
	string arrMonthNames[] = {
	"Jan","Feb","Mar","Apr","May","Jun",
	"Jul","Aug","Sep","Oct","Nov","Dec"
	};
	return arrMonthNames[Month - 1];
}

void FillMonthMatrix(short MatrixMonthCalendar[6][7], short NumberOfDays, short FirstDayInTheWeek)
{
	short Count = 0;

	for (short Row = 0; Row < 6; Row++)
	{
		for (short Col = FirstDayInTheWeek; Col < 7; Col++)
		{
			Count++;
			if (Count <= NumberOfDays)
			{
				MatrixMonthCalendar[Row][Col] = Count;
			}
			else
			{
				break;
			}


		}
		FirstDayInTheWeek = 0;
	}


}

void printMatrix(short MatrixMonthCalendar[6][7])
{
	for (short Row = 0; Row < 6; Row++)
	{
		for (short Col = 0; Col < 7; Col++)
		{
			(MatrixMonthCalendar[Row][Col] < 0) ? cout << setw(5) << "" : cout << setw(5) << MatrixMonthCalendar[Row][Col];

		}
		cout << endl;
	}
}

void PrintMonthCalendar(short Month, short Year)
{
	short NumberOfDays = NumberOfDaysInMonth(Month, Year);
	short FirstDayInTheWeek = DayOfWeekOrder(1, Month, Year);
	short MatrixMonthCalendar[6][7];


	FillMonthMatrix(MatrixMonthCalendar, NumberOfDays, FirstDayInTheWeek);

	cout << "-----------------" << MonthShortName(Month) << "--------------------\n";
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
	printMatrix(MatrixMonthCalendar);
	cout << "-----------------------------------------\n";
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	PrintMonthCalendar(Month, Year);
	system("pause>0");


	return 0;
}