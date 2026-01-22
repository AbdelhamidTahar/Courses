#include <iostream>
#include <cmath>
using namespace std;

void stodhms()
{
    unsigned int total_seconds, number_of_days, number_of_hours, number_of_minutes, number_of_seconds, remainde_r;

    const unsigned int seconds_per_day = 24 * 60 * 60;
    const unsigned int seconds_per_hour = 60 * 60;
    const unsigned int seconds_per_minute = 60;

    cout << "Please enter the TOTAL SECONDS?" << endl;
    cin >> total_seconds;

    number_of_days = floor(total_seconds / seconds_per_day);
    remainde_r = total_seconds % seconds_per_day;

    number_of_hours = floor(remainde_r / seconds_per_hour);
    remainde_r = remainde_r % seconds_per_hour;

    number_of_minutes = floor(remainde_r / seconds_per_minute);

    remainde_r = remainde_r % seconds_per_minute;

    number_of_seconds = remainde_r;

    cout << number_of_days << ":" << number_of_hours << ":" << number_of_minutes << ":" << number_of_seconds << endl;
}


int main()
{


    stodhms();

    return 0;
}