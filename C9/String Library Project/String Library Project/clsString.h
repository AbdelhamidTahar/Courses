#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Value;
	 static bool _IsVowel(char Letter)
	{

		Letter = tolower(Letter);
		return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
	}

public:
	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static string UpperAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}
		return Text;
	}
	string UpperAllString()
	{
		return UpperAllString(_Value);
	}

	static string LowerAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}
		return Text;
	}
	string LowerAllString()
	{
		return LowerAllString(_Value);
	}

	static void PrintFirstLetterOfEachWord(string S)
	{
		bool isFirstLetter = true;

		cout << "\nFirst letters of this string: \n";

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstLetter)
			{
				cout << S[i] << endl;
			}

			isFirstLetter = S[i] == ' ' ? true : false;
		}
	}
	void  PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstLetter)
			{
				S[i] = toupper(S[i]);
			}
			isFirstLetter = S[i] == ' ' ? true : false;
		}

		return S;
	}
	string UpperFirstLetterOfEachWord()
	{
		return UpperFirstLetterOfEachWord(_Value);
	}


	static string LowerFirstLetterOfEachWord(string S)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstLetter)
			{
				S[i] = tolower(S[i]);
			}
			isFirstLetter = S[i] == ' ' ? true : false;
		}

		return S;
	}
	string LowerFirstLetterOfEachWord()
	{
		return LowerFirstLetterOfEachWord(_Value);
	}

	static short CountCapitalLetters(const string& S)
	{
		short Count = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (isupper(S[i]))
			{
				Count++;
			}
		}
		return Count;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(const string& S)
	{
		short Count = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (islower(S[i]))
			{
				Count++;
			}
		}
		return Count;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static short CountLetters(const string& S, enWhatToCount WhatToCount)
	{
		short Count = 0;

		if (WhatToCount == enWhatToCount::All)
		{
			return S.length();
		}

		for (short i = 0; i < S.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S[i]))
			{
				Count++;
			}

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S[i]))
			{
				Count++;
			}


		}
		return Count;
	}
	short CountLetters(enWhatToCount WhatToCount)
	{
		return CountLetters(_Value, WhatToCount);
	}

	static short CountLetter(const string& S, const char& Character)
	{
		short Count = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] == Character)
			{
				Count++;
			}
		}
		return Count;
	}
	short CountLetter(const char& Character)
	{
		return CountLetter(_Value, Character);
	}

	static short CountVowels(const string& S)
	{
		short Count = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (_IsVowel(S[i]))
				Count++;
		}
		return Count;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintVowels(const string& S)
	{
		cout << "\nVowels in string are: ";
		for (short i = 0; i < S.length(); i++)
		{
			if (_IsVowel(S[i]))
				cout << S[i] << "    ";
		}

	}
	void PrintVowels()
	{
		PrintVowels(_Value);
	}
	
	static void PrintEachWordInString(string S)
	{
		string delim = " ";
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord;
		while ((pos = S.find(delim)) != std::string::npos)
		{
			sWord = S.substr(0, pos);
			if (sWord != "")
				cout << sWord << endl;
			S = S.erase(0, pos + 1);
		}
		if (S != "")
		{
			cout << S << endl;
		}


	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static short CountWords(string S1)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				Counter++;
			}
			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	static vector<string> SplitString(string S, string Delim)
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
	vector<string> SplitString(string Delim)
	{
		return SplitString(_Value, Delim);
	}

	static string TrimLeft(string S)
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
	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

	static string TrimRigth(string S)
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
	string TrimRigth()
	{
		return TrimRigth(_Value);
	}

	static string Trim(string S)
	{
		return TrimRigth(TrimLeft(S));
	}
	string Trim()
	{
		return Trim(_Value);
	}

	static string ReverseWordsInString(string S)
	{
		vector<string> vWords = SplitString(S, " ");
		string S2 = "";
		vector<string>::iterator iter = vWords.end();

		while (iter != vWords.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		return  S2.substr(0, S2.length() - 1);
	}
	string ReverseWordsInString()
	{
		return ReverseWordsInString(_Value);
	}

	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string
		StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
			pos = S1.find(StringToReplace);
		}

		return S1;

	}
	string ReplaceWordInStringUsingBuiltInFunction(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWordInStringUsingBuiltInFunction(_Value, StringToReplace, sRepalceTo);
	}

	static string RemovePunctuationsFromString(string S)
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
	string RemovePunctuationsFromString()
	{
		return RemovePunctuationsFromString(_Value);
	}
};

