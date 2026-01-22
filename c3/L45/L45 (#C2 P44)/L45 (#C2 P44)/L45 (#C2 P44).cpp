#include <iostream>
using namespace std;

enum days { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

void readchoseday(days& enday)
{
	int choseday;
	cout << "*****************************\n";
	cout << "(1)Sunday\n";
	cout << "(2)Monday\n";
	cout << "(3)Tuesday\n";
	cout << "(4)Wednesday\n";
	cout << "(5)Thursday\n";
	cout << "(6)Friday\n";
	cout << "(7)Saturday\n";
	cout << "*****************************\n";

	cout << "Please neter you shoce" << endl;

	cin >> choseday;
	enday = days(choseday);
}

string checkforshoce(days enday)
{
	switch (enday)
	{
	case days::Sunday:
		return "Sunday";
		break;

	case days::Monday:
		return "Monday";
		break;

	case days::Tuesday:
		return "Tuesday";
		break;

	case days::Wednesday:
		return "Wednesday";
		break;

	case days::Thursday:
		return "Thursday";
		break;

	case days::Friday:
		return "Friday";
		break;

	case days::Saturday:
		return "Saturday";
		break;

	default:
		return "WRONG SHOCE";
	}
}

void printchose(string shoce)
{
	cout << shoce << endl;
}

int main()
{

	days enday;

	readchoseday(enday);
	printchose(checkforshoce(enday));


	return 0;
}