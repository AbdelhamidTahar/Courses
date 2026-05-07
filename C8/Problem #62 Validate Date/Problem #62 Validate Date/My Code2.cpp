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
    if (Month < 1 || Month > 12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
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

bool IsValidMonth(short Month)
{
    return (Month >= 1 && Month <= 12);
}

bool IsValidDay(stDate Date)
{
    if (Date.Day < 1)
        return false;

    short NumberOfDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (NumberOfDays == 0)
        return false;

    return (Date.Day > NumberOfDays) ? false : true;
}

bool IsValidDate(stDate Date)
{
    return (IsValidMonth(Date.Month) && IsValidDay(Date) );
}

int main()
{


    cout << "\nEnter Date :";
    stDate Date = ReadFullDate();

    if (IsValidDate(Date))
        cout << "\nYes Date is Validate\n";
    else
        cout << "\nNo Date is Validate\n";

    system("pause>0");
    return 0;
}
