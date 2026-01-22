#include <iostream>
using namespace std;

enum Monthyear { January=1, February, March, April, May, June, July, August, September, October, November,December };

void ShowMonthyearMenu()
{
	cout << "******************************\n";
		cout << "\t" << "Month Year" << "\t\n";
		cout << "******************************\n";
		cout << "1: January\n";
		cout << "2: February\n";
		cout << "3: March\n";
		cout << "4: April\n";
		cout << "5: May\n";
		cout << "6: June\n";
		cout << "7: July\n";
		cout << "8: August\n";
		cout << "9: September\n";
		cout << "10: October\n";
		cout << "11: November\n";
		cout << "12: December\n";
		cout << "******************************\n";
		cout << "Please enter the number of Month" << endl;
}

Monthyear ReadMonthYear()
{
	int NumberMonth;

	cin >> NumberMonth;
	return (Monthyear)NumberMonth;

}

string GetWeekMonthName(Monthyear NumberMonth)
{
	switch (NumberMonth)
	{
	case Monthyear::January:
		return "January";
		break;
	case Monthyear::February:
		return "February";
		break;
	case Monthyear::March:
		return "March";
		break;
	case Monthyear::April:
		return "April";
		break;
	case Monthyear::May:
		return "May";
		break;
	case Monthyear::June:
		return "June";
		break;
	case Monthyear::July:
		return "July";
		break;
	case Monthyear::August:
		return "August";
		break;
	case Monthyear::September:
		return "September";
		break;
	case Monthyear::October:
		return "October";
		break;
	case Monthyear::November:
		return "November";
		break;
	case Monthyear::December:
		return "December";
		break;
	default :
		return "00";
	}
}

int main()
{
	ShowMonthyearMenu();
	cout << "Month is " << GetWeekMonthName( ReadMonthYear() ) << endl;

	return 0;
}


