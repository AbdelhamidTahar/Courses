#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

/*
int tm_sec; // seconds of minutes from 0 to 61
int tm_min; // minutes of hour from 0 to 59
int tm_hour; // hours of day from 0 to 24
int tm_mday; // day of month from 1 to 31
int tm_mon; // month of year from 0 to 11 (+1)
int tm_year; // year since 1900
int tm_wday; // days since sunday
int tm_yday; // days since January 1st
int tm_isdst; // hours of daylight savings time
*/
int main()
{
    time_t TimeInSeconds;
    TimeInSeconds = time(0);

    tm* PstrLocalTime;
    PstrLocalTime = localtime(&TimeInSeconds);

    cout << "Day: " << PstrLocalTime->tm_mday << endl;
    cout << "Month: " << PstrLocalTime->tm_mon + 1 << endl;
    cout << "Year: " << PstrLocalTime->tm_year + 1900 << endl;
    cout << "Second: " << PstrLocalTime->tm_sec << endl;
    cout << "Minet: " << PstrLocalTime->tm_min << endl;
    cout << "Hour: " << PstrLocalTime->tm_hour << endl;

    cout << "days since sunday: " << PstrLocalTime->tm_wday << endl;
    cout << "days since January 1st: " << PstrLocalTime->tm_yday << endl;
    cout << "hours of daylight savings time: " << PstrLocalTime->tm_isdst << endl;

    return 0;

}