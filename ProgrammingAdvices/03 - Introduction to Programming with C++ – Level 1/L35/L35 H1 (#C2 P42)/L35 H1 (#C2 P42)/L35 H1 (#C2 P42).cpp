//42
#include <iostream>
using namespace std;

unsigned int total_seconds(unsigned short number_of_days, unsigned short number_of_hours, unsigned short number_of_minutes, unsigned short number_of_seconds)
{

    return (number_of_days * 24 * 60 * 60) + (number_of_hours * 60 * 60) + (number_of_minutes * 60) + number_of_seconds;
}

int main()
{
    unsigned short number_of_days, number_of_hours, number_of_minutes, number_of_seconds;

    cout << "please enter then number of days" << endl;
    cin >> number_of_days;

    cout << "please enter then number of hours" << endl;
    cin >> number_of_hours;

    cout << "please enter then number of minutes" << endl;
    cin >> number_of_minutes;

    cout << "please enter then number of seconds" << endl;
    cin >> number_of_seconds;

    cout << "\n" << total_seconds(number_of_days, number_of_hours, number_of_minutes, number_of_seconds) << " SECONDS" << endl;

    return 0;
}