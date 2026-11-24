#include <iostream>
using namespace std;

struct strInfo
{
	int Age;
    bool HasDrivingLicnse;
};

strInfo ReadInfo()
{
	strInfo Info;

	cout << "Please enter your age?" << endl;
	cin >> Info.Age;

	cout << "Do you have driving licene?" << endl;
	cin >> Info.HasDrivingLicnse;

	return Info;
}

bool IsAccepted(strInfo Info)
{
	return (Info.Age > 21 && Info.HasDrivingLicnse);
}

void PrintREsult(strInfo Info)
{
	if (IsAccepted(Info) )
	{
		cout << "\nHired" << endl;
	}
	else
	{
		cout << "\nRejected" << endl;
	}
}

int main()
{

	PrintREsult(ReadInfo());

	return 0;
}