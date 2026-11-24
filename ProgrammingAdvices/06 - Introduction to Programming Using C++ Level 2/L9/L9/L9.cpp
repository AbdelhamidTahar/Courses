#include <iostream>
using namespace std;

int main()
{
	int Mark = 99;
	string Result = "";



	if (Mark >= 50)
	{
		Result = "Pass";
	}
	else
	{
		Result = "Fail";
	}
	cout << Result << endl;

	(Mark >= 50) ? (Mark >= 50) ? cout << "YEs" : cout << "No" : cout << Result;
	


}