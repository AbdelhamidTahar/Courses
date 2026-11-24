#include <iostream>
#include <cctype>
#include <vector>
#include "InputLib.h"


using namespace std;

vector<string> SplitString(string S, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S.find(Delim)) != std::string::npos)
	{
		sWord = S.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S.erase(0, pos + Delim.length()); /* erase() until
		positon and move to next word. */
	}
	if (S != "")
	{
		vString.push_back(S); // it adds last word of the string.
	}
	return vString;
}

int main()
{
	vector<string> vString;
	vString = SplitString(UserInput::ReadString(), " ");
	cout << "\nTokens = " << vString.size() << endl;
	for (string& s : vString)
	{
		cout << s << endl;
	}
}
