#include <iostream>
#include <cctype>
#include <vector>
#include "InputLib.h"
using namespace std;

string TrimLeft(string S)
{

	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ')
		{
			return S.substr(i, S.length() - i);
		}
	}
	return "";
}

string TrimRigth(string S)
{
	for (short i = S.length() - 1; i >= 0; i--)
	{
		if (S[i] != ' ')
		{
			return S.substr(0, i + 1);
		}
	}
	return"";
}

string Trim(string S)
{

	return TrimRigth(TrimLeft(S));
}


int main()
{
	string S = "      Abdelhamid Tahar       ";
	cout << "String       = " << S << endl;
	cout << "Trim left    = " << TrimLeft(S) << endl;
	cout << "Trim Rigth   = " << TrimRigth(S) << endl;
	cout << "Trim Rigth   = " << Trim(S) << endl;

}
