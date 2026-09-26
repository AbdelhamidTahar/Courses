#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Value;

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

	static short Length(const string& Text)
	{
		return Text.length();
	}
	short Length()
	{
		return Length(_Value);
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
	void PrintFirstLetterOfEachWord()
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
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
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
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}
		return Text;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}
		return Text;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Char)
	{
		return isupper(Char) ? tolower(Char) : toupper(Char);
	}

	static string InvertAllLettersCase(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = InvertLetterCase(S[i]);
		}
		return S;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static short CountLetters(const string& S, enWhatToCount WhatToCount = enWhatToCount::All)
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
	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
	{
		return CountLetters(_Value, WhatToCount);
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

	static short CountSpecificLetter(const string& S, const char& Character, bool Sinsatev = true)
	{
		short Count = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (Sinsatev)
			{
				if (S[i] == Character)
				{
					Count++;
				}
			}
			else
			{
				if (tolower(S[i]) == tolower(Character))
				{
					Count++;
				}
			}
		}
		return Count;
	}
	short CountSpecificLetter(const char& Character, bool Sinsatev = true)
	{
		return CountSpecificLetter(_Value, Character, Sinsatev);
	}

	static bool IsVowel(char Letter)
	{

		Letter = tolower(Letter);
		return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
	}

	static short CountVowels(const string& S)
	{
		short Count = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (IsVowel(S[i]))
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
			if (IsVowel(S[i]))
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

	static vector<string> Split(string S, string Delim)
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
	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
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
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S)
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
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S)
	{

		return TrimRight(TrimLeft(S));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string>vString, string Delim)
	{
		string S1 = "";

		for (string& Elemnet : vString)
		{
			S1 = S1 + Elemnet + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());

	}

	static string JoinString(string arrString[], short arrLengh, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < arrLengh; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReverseWordsInString(string S)
	{
		vector<string> vWords = Split(S, " ");
		string S2 = "";
		vector<string>::iterator iter = vWords.end();

		while (iter != vWords.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		return  S2.substr(0, S2.length() - 1);
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}


	static 	string ReplaceWord
	    (string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}
			}
		}

		return JoinString(vString, " ");
	}
	void ReplaceWord(string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		_Value = ReplaceWord(_Value, StringToReplace, sRepalceTo,  MatchCase);
	}


	static string RemovePunctuations(string S)
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
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}


};

