#include <iostream>
using namespace std;



void readnumberofmonth(short& numberofmonth)
{
	cout << "Please enter number of month?" << endl;
	cin >> numberofmonth;
}

string checkofmonth(short numberofmonth)
{
	if (numberofmonth > 12 || numberofmonth < 1)
	{
		return "Wrong month";
	}
	else if (numberofmonth == 1)
	{
		return "January";
	}
	else if (numberofmonth == 2)
	{
		return "February";
	}
	else if (numberofmonth == 3)
	{
		return "March";
	}
	else if (numberofmonth == 4)
	{
		return "April";
	}
	else if (numberofmonth == 5)
	{
		return "May";
	}
	else if (numberofmonth == 6)
	{
		return "June";
	}
	else if (numberofmonth == 7)
	{
		return "July";
	}
	else if (numberofmonth == 8)
	{
		return "August";
	}
	else if (numberofmonth == 9)
	{
		return "September";
	}
	else if (numberofmonth == 10)
	{
		return "October";
	}
	else if (numberofmonth == 11)
	{
		return "November";
	}
	else 
	{
		return "December";
	}
}

void printday(string moth)
{
	cout << moth << endl;
}

int main()
{
	short numberofmoth;

	readnumberofmonth(numberofmoth);
	printday(checkofmonth(numberofmoth));

	return 0;
}