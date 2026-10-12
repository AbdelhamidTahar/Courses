#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t\t_______________________________________________________\n";
		cout << "\t\t\t\t\t\t\t\t\tTitle\n";
		if (SubTitle != "")
			cout << "\t\t\t\t\t\t\t\t\tSubTitle\n";

		cout << "\t\t\t\t\t\t_______________________________________________________\n";
	}
};

