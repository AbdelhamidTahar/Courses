#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "clsString.h"
#include <string>
#include <vector>

using namespace std;

class clsDate :public clsString
{
private:
	short _Year;
	short _Month;
	short _Day;
public:

	clsDate()
	{
		time_t TimeInSeconds = time(0);
		tm* Date = localtime(&TimeInSeconds);

		this->_Day = Date->tm_mday;
		this->_Day = Date->tm_mon + 1;
		this->_Day = Date->tm_year + 1990;
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year)
	{
		*this = GetDateFromDayOrderInYear(DateOrderInYear, Year);
	}

	clsDate GetSystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;
		return Date;
	}
	


	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property( get = GetYear,put = SetYear)) short Year;






	static bool IsLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 100
		// OR if year is divisible by 400
		// then it is a leap year
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;
	}
	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(this->_Day, this->_Month, this->_Year);
	}

	
	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}
	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) :
			days[Month - 1];
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}
	string MonthShortName()
	{
		return  MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		// Print the current month name
		printf("\n _______________%s_______________\n\n",
			MonthShortName(Month).c_str());
		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");
		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n _________________________________\n");
	}
	void PrintMonthCalendar()
	{
		 PrintMonthCalendar(_Month, Year);
	}

	static clsDate DateAddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	void DateAddDays(short Days)
	{
		*this =  DateAddDays(Days, *this);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(this->_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{

		return NumberOfDaysInYear(Year) * 24;
	}
	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(this->_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{

		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(this->_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{

		return NumberOfMinutesInYear(Year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(this->_Year);
	}

	static void PrintCertainYear(short Year)
	{
		cout << "\n\n";
		cout << "Number Of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year) << endl;
		cout << "Number Of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear(Year) << endl;
		cout << "Number Of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year) << endl;
		cout << "Number Of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year) << endl;
	}
	void PrintCertainYear()
	{
		PrintCertainYear(this->_Year);
	}


	static short NumberOfHoursInMonth(short Month, short Year)
	{

		return NumberOfDaysInAMonth(Month, Year) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(this->_Month, this->_Year);
	}


	static int NumberOfMinutesInMonth(short Month, short Year)
	{

		return NumberOfHoursInMonth(Month, Year) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return  NumberOfMinutesInMonth(this->_Month, this->_Year);
	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{

		return NumberOfMinutesInMonth(Month, Year) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(this->_Month, this->_Year);
	}

	static void PrintCertainMonth(short Month, short Year)
	{
		cout << "\n\n";
		cout << "Number Of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year) << endl;
		cout << "Number Of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Month, Year) << endl;
		cout << "Number Of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Month, Year) << endl;
		cout << "Number Of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Month, Year) << endl;
	}
	void PrintCertainMonth()
	{
		PrintCertainMonth(this->_Month, this->_Year);
	}


	static string GetDayName(short Day, short Month, short Year)
	{
		return DayShortName(DayOfWeekOrder(Day, Month, Year));
	}
	string GetDayName()
	{
		return DayShortName();
	}

	static void PrintDayName(short Day, short Month, short Year)
	{
		cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
		cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
		cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Day,
			Month, Year));
	}
	void PrintDayName()
	{
		PrintDayName(this->_Day, this->_Month, this->_Year);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n _________________________________\n\n");
		printf("         Calendar - %d\n", Year);
		printf(" _________________________________\n");


		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(this->_Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(this->_Day, this->_Month, this->_Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date.Year = Year;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	 clsDate GetDateFromDayOrderInYear(short DateOrderInYear)
	{
		 return GetDateFromDayOrderInYear(DateOrderInYear, this->_Year);
	}


	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{

		return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
			Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
				Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	};
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	};
	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(this->_Month);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date)
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
	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;
		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;
		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}
	void SwapDates(clsDate& Date2)
	{
		SwapDates(*this, Date2);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SawpFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SawpFlagValue : Days *
			SawpFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}
	
	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}


	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void  DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void  DecreaseDateByXWeeks(short Weeks)
	{
		*this = DecreaseDateByXWeeks(Weeks , *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
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
	void  DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void  DecreaseDateByXDays(short Days)
	{
		*this = DecreaseDateByXDays(Days , *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void  DecreaseDateByXMonths(short Months)
	{
		*this = DecreaseDateByXMonths(Months ,*this);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date.Year++;
		return Date;
	}
	void  DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}


	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{
		Date.Year += Years;
		return Date;
	}
	void  DecreaseDateByXYears(short Years)
	{
		*this = DecreaseDateByXYears( Years ,*this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	}
	void  DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}



	static clsDate DecreaseDateByXDecades(short Decade, clsDate Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}
	void  DecreaseDateByXDecades(short Decade)
	{
		*this = DecreaseDateByXDecades(Decade ,*this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		//Period of 100 years
		Date.Year += 100;
		return Date;
	}
	void  DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		//Period of 1000 years
		Date.Year += 1000;
		return Date;
	}
	void  DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DaysCount;
	}
	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	clsDate CalculateVacationReturnDate(short VacationDays)
	{
		return CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		/* if (IsDate1AfterDate2(Date1,Date2))
		return enDateCompare::After;*/

		//this is faster
		return enDateCompare::After;
	}
	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool IsOverlapPeriods(
		clsDate StartPeriod1, clsDate EndPeriod1,
		clsDate StartPeriod2, clsDate EndPeriod2
	)
	{
		if (CompareDates(EndPeriod2, StartPeriod1) == enDateCompare::Before
			|| CompareDates(StartPeriod2, EndPeriod1) == enDateCompare::After)
			return false;
		else
			return true;
	}

	static int PeriodLengthInDays(clsDate StartPeriod, clsDate EndPeriod, bool IncludeEndDate = false)
	{
		return GetDifferenceInDays(StartPeriod, EndPeriod, IncludeEndDate);
	}


	static bool isDateInPeriod(clsDate Date, clsDate StartPeriod, clsDate EndPeriod)
	{
		return !(CompareDates(Date, StartPeriod) == enDateCompare::Before
			|| CompareDates(Date, EndPeriod) == enDateCompare::After);
	}
	bool isDateInPeriod(clsDate StartPeriod, clsDate EndPeriod)
	{
		return isDateInPeriod(*this, StartPeriod, EndPeriod);
	}

	int CountOverlapDays(
		clsDate StartPeriod1, clsDate EndPeriod1,
		clsDate StartPeriod2, clsDate EndPeriod2
	)
	{
		int Period1Length = PeriodLengthInDays(StartPeriod1, EndPeriod1, true);
		int Period2Length = PeriodLengthInDays(StartPeriod2, EndPeriod2, true);
		int OverlapDays = 0;

		if (!IsOverlapPeriods(StartPeriod1, EndPeriod1, StartPeriod2, EndPeriod2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(StartPeriod1, EndPeriod1))
			{
				if (isDateInPeriod(StartPeriod1, StartPeriod2, EndPeriod2))
					OverlapDays++;
				StartPeriod1 = IncreaseDateByOneDay(StartPeriod1);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(StartPeriod2, EndPeriod1))
			{
				if (isDateInPeriod(StartPeriod2, StartPeriod1, EndPeriod1))
					OverlapDays++;
				StartPeriod2 = IncreaseDateByOneDay(StartPeriod2);
			}
		}
		return OverlapDays;
	}

	static bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > DaysInMonth)
			return false;

		return true;
	}
	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector<string> vDate;
		vDate = clsString::Split(DateString, "/");

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	static string FormateDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "yyyy", to_string(Date.Year));
		return FormattedDateString;
	}

	static short IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}
	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{
		clsDate EndOfMontDate;

		EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;

		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

};

