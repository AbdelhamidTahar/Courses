#include<iostream>
#include<cctype>
#include<string>
using namespace std;



string RemovePunctuationsFromString(string S)
{
	string S2 = "";

	for (short i = 0; i < S.length(); i++)
	{
		if (!ispunct(S[i]))
		{
			S2 += S[i];
		}
	}
	return S2;
}



int main()
{
	string S = "Welcom, to jorden jorden it's a very nice country; it's amazing.";

	cout << "Original String:\n" << S;
	

	cout << "\n\nPunctuations Removed:\n";
	S = RemovePunctuationsFromString(S);
	cout << S << endl;


	return 0;
}