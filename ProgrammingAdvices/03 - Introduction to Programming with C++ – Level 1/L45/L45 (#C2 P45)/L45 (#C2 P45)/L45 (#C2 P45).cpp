#include <iostream>
using namespace std;

enum moths { January=1, February, March, April, May, June, July, August, September, October, November,December };

void readtheselectedmonthnumber(unsigned short &selectmonthnumber)
{

	cout << "********************************\n";
	cout << "(1)January                     *\n";
	cout << "(2)February                    *\n";;
	cout << "(3)March                       *\n";
	cout << "(4)April                       *\n";
	cout << "(5)May                         *\n";
	cout << "(6)June                        *\n";
	cout << "(7)July                        *\n";
	cout << "(8)August                      *\n";
	cout << "(9)September                   *\n";
	cout << "(10)October                    *\n";
	cout << "(11)November                   *\n";
	cout << "(12)December                   *\n";
	cout << "********************************\n";

	cout << "Please chose moth?" << endl;

	cin >> selectmonthnumber;
}

void converttheselectedmonthnumbertoamonth(unsigned short selectmonthnumber, moths& enselectedmonth)
{
	enselectedmonth = (moths)selectmonthnumber;
}

string verifytheselectedmonth(moths enselectedmonth)
{
	switch(enselectedmonth)
	{
	case moths::January:
		return "January";
		break;
	case moths::February:
		return "February";
		break;
	case moths::March:
		return "March";
		break;
	case moths::April:
		return "April";
		break;
	case moths::May:
		return "May";
		break;
	case moths::June:
		return "June";
		break;
	case moths::July:
		return "July";
		break;
	case moths::August:
		return "August";
		break;
	case moths::September:
		return "September";
		break;
	case moths::October:
		return "October";
		break;
	case moths::November:
		return "November";
		break;
	case moths::December:
		return "December";
		break;
	default :
		return "WRONG SELECTED MONTH";
	}
}

void printtheselevtedmonth(string seltctedmonth)
{
	cout << seltctedmonth << endl;
}

int main()
{
	unsigned short selectmonthnumber;
	moths enselectedmonth;

	readtheselectedmonthnumber(selectmonthnumber);
	converttheselectedmonthnumbertoamonth(selectmonthnumber, enselectedmonth);
	printtheselevtedmonth(verifytheselectedmonth(enselectedmonth));


	return 0;
}
