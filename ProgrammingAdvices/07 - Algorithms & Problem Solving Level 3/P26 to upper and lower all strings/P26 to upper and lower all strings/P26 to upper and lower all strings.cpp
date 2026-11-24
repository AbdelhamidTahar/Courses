#include <iostream>
#include <cctype>
#include "InputLib.h"
using namespace std;

string UpperAllString(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}
	return Text;
}

string LowerAllString(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}
	return Text;
}



int main()
{
	string UpperString;

	UpperString = User_Input::ReadString();
	UpperString = UpperAllString(UpperString);

	cout << "\nstrint After Upper\n";
	cout << UpperString << "\n";


	UpperString = LowerAllString(UpperString);

	cout << "\nstrint After Lower\n";
	cout << UpperString << "\n";

	return 0;
}
