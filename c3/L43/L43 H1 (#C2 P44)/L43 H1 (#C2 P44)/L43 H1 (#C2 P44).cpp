#include <iostream>
using namespace std;



void readnumberofday(short& numberofday)
{
	cout << "Please enter number of day?" << endl;
	cin >> numberofday;
}

string checkofday(short numberofday)
{
	if (numberofday > 7 || numberofday < 1)
	{
		return "Wrong day";
	}
	else if (numberofday == 1)
	{
		return "sunday";
	}
	else if (numberofday == 2)
	{
		return "monday";
	}
	else if (numberofday == 3)
	{
		return "tuesday";
	}
	else if (numberofday == 4)
	{
		return "wednesday";
	}
	else if (numberofday == 5)
	{
		return "thursday";
	}
	else if (numberofday == 6)
	{
		return "friday";
	}
	else
	{
		return "saturday";
	}
}

void printday(string day)
{
	cout << "Its " << day << endl;
}

int main()
{
	short numberofday;

	readnumberofday(numberofday);
	printday ( checkofday(numberofday) );

	return 0;
}