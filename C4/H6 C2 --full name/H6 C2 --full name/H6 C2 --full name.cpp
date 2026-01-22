#include <iostream>
using namespace std;

enum enFormatFullName{FirstName=1,LastName = 2};

struct strInfo
{
	string FirstName;
	string LastName;
};

strInfo ReadInfo()
{
	strInfo Info;

	cout << "Please enter your First Name" << endl;
	cin >> Info.FirstName;

	cout << "Please enter your Last Name" << endl;
	cin >> Info.LastName;

	return Info;
}

string GetFullName(strInfo Info , bool Reversed)
{
	string FullName = "";
	if (Reversed)
		FullName= Info.LastName + " " + Info.FirstName;
	else 
		FullName= Info.FirstName + " " + Info.LastName;
 
	return FullName;
}

void PrintFullName(string FullName)
{
	cout << "\nYour Full Name Is: " << FullName << endl;
}

int main()
{

	PrintFullName( GetFullName( ReadInfo() , false) );

}