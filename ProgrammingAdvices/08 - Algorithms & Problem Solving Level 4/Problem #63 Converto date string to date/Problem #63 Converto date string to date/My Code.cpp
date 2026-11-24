#include <iostream>
#include <cctype>
#include <string>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

string ReadDateString()
{
	string DateString;
	cout << "Please Enter Date dd/mm/yyyy? ";
	cin >> DateString;
	return DateString;
}

stDate ConvertFromDateStringToDateStruct(string DateString, string Delim)
{
	stDate Date;
	short LengthDelim = Delim.length();
	short Pos = 0;

	//cut Day.
	if ((Pos = DateString.find(Delim)) != std::string::npos)
	{
		Date.Day = stoi(DateString.substr(0, Pos));
		DateString = DateString.erase(0, Pos + LengthDelim);
	}

	//cut Month
	if ((Pos = DateString.find(Delim)) != std::string::npos)
	{
		Date.Month = stoi(DateString.substr(0, Pos));
		DateString = DateString.erase(0, Pos + LengthDelim);
	}
	//Remind is Year.
	Date.Year = stoi(DateString);

	return Date;
}

string ConvertFromDateStructToDateString(stDate Date, string Delim)
{
	return to_string(Date.Day) + Delim + to_string(Date.Month) + Delim + to_string(Date.Year);
}

int main()
{
	string DateString = ReadDateString();

	stDate Date = ConvertFromDateStringToDateStruct(DateString, "/");
	cout << "\nDay: " << Date.Day;
	cout << "\nMonth: " << Date.Month;
	cout << "\nYear: " << Date.Year;

	cout << "\n\nYou entered: " << ConvertFromDateStructToDateString(Date, "/");

	return 0;
}