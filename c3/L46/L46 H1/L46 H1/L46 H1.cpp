#include <iostream>
using namespace std;

enum enWeekday {Sun=1,Mon=2,Tue=3,Wed=4,Thu=5,Fri=6,Sat=7};

void Showweekdaymenu()
{
	cout << "******************************\n";
	cout << "\t" << "Week Days" << "\t\n";
	cout << "******************************\n";
	cout << "1: Sunday\n";
	cout << "2: Monday\n";
	cout << "3: Tuesday\n";
	cout << "4: Wednesday\n";
	cout << "5: Thursday\n";
	cout << "6: Friday\n";
	cout << "7: Saturday\n";
	cout << "******************************\n";
	cout << "Please enter the number of day" << endl;
}

enWeekday ReadWeekday()
{
	int weekday;

	cin >> weekday;
	return (enWeekday)weekday;
	
}

string GetWeekDayName(enWeekday WeekDay)
{
	switch (WeekDay)
	{
	case enWeekday::Sun:
		return "Sunday";
		break;
	case enWeekday::Mon:
		return "Monday";
		break;
	case enWeekday::Tue:
		return "Tuesday";
		break;
	case enWeekday::Wed:
		return "Wednesday";
		break;
	case enWeekday::Thu:
		return "Thursday";
		break;
	case enWeekday::Fri:
		return "Friday";
		break;
	case enWeekday::Sat:
		return "Saturday";
		break;
	default:
		return "00";
	}
}

int main()
{
	Showweekdaymenu();
	cout << "Today is " <<GetWeekDayName(ReadWeekday()) << endl;

	return 0;
}