#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;



namespace OperationsOnString
{
    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    void PrintFirstLetterOfEachWord(string S);
    string UpperFirstLetterOfEachWord(string S);
    string LowerFirstLetterOfEachWord(string S);
    string UpperAllString(string S);
    string LowerAllString(string S);
    string InvertAllStringLettersCase(string S);
    short CountLetters(const string& S, enWhatToCount WhatToCount = enWhatToCount::All);
    short CountCapitalLetters(const string& S);
    short CountSmallLetters(const string& S);
    //CountDigit
    //CountSymbol
    short CountLetter(const string& S, const char& Letter, bool MatchCase = true);
    short CountVowels(const string& S);
    void  PrintEachWordInString(string S);
    short CountWords(string S1);
    vector<string>SplitString(string S, string Delim);
    string TrimLeft(string S);
    string TrimRigth(string S);
    string Trim(string S);
    string JoinString(vector<string>vString, string Delim);
    string ReverseWordsInString(string S);
    string ReplaceWordInStringUsingBuiltInFunction(string S1, string
        StringToReplace, string sRepalceTo);
    vector<string> ChangWord(vector<string>vString, string Word, string WordToReplace, bool Sensitive = true);
    string ReplaceWordInString(string S1, string Delim, string Word, string WordToReplace, bool Sensitive = true);
    string ReplaceWordInStringUsingSplit
    (string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true);
    string RemovePunctuationsFromString(string S);

}

namespace OperationsOnChar
{
    char InvertLetterCase(char Char);
    bool IsVowel(char Letter);

}

string OperationsOnString::RemovePunctuationsFromString(string S)
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


string OperationsOnString::ReplaceWordInStringUsingSplit
(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
    vector<string> vString = SplitString(S1, " ");

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

    return OperationsOnString::JoinString(vString, " ");
}

string OperationsOnString::ReplaceWordInString(string S1, string Delim, string Word, string WordToReplace, bool Sensitive )
{
    vector<string>vS;
    vS = SplitString(S1, Delim);
    vS = ChangWord(vS, Word, WordToReplace, Sensitive);

    return JoinString(vS, Delim);
}

vector<string> OperationsOnString::ChangWord(vector<string>vString, string Word, string WordToReplace, bool Sensitive )
{

    for (string& Element : vString)
    {
        if (Sensitive)
        {
            if (Element == Word)
            {
                Element = WordToReplace;
            }
        }
        else
        {
            if (OperationsOnString::LowerAllString(Element) == OperationsOnString::LowerAllString(Word))
            {
                Element = WordToReplace;
            }
        }
    }


    return vString;
}

string OperationsOnString::ReplaceWordInStringUsingBuiltInFunction(string S1, string
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

string OperationsOnString::JoinString(vector<string>vString, string Delim)
{
    string S1 = "";

    for (string& Elemnet : vString)
    {
        S1 = S1 + Elemnet + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());

}


string OperationsOnString:: TrimLeft(string S)
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

string OperationsOnString::TrimRigth(string S)
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

string OperationsOnString::Trim(string S)
{

    return TrimRigth(TrimLeft(S));
}

short OperationsOnString::CountVowels(const string& S)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (OperationsOnChar::IsVowel(S[i]))
            Count++;
    }
    return Count;
}


short OperationsOnString::CountLetter(const string& S, const char& Letter, bool MatchCase)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (MatchCase)
        {
            if (S[i] == Letter)
            {
                Count++;
            }
        }
        else
        {
            if (tolower(S[i]) == tolower(Letter))
            {
                Count++;
            }
        }
    }
    return Count;
}


short OperationsOnString::CountLetters(const string& S, enWhatToCount WhatToCount)
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

short OperationsOnString::CountCapitalLetters(const string& S)
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

short OperationsOnString::CountSmallLetters(const string& S)
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


string OperationsOnString::InvertAllStringLettersCase(string S)
{
    for (short i = 0; i < S.length(); i++)
    {
        S[i] = OperationsOnChar::InvertLetterCase(S[i]);
    }
    return S;
}

void OperationsOnString::PrintEachWordInString(string S)
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

short OperationsOnString::CountWords(string S1)
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

vector<string>OperationsOnString::SplitString(string S, string Delim)
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

string OperationsOnString::ReverseWordsInString(string S)
{
    vector<string> vWords = SplitString(S, " ");
    string S2 = "";
    vector<string>::iterator iter = vWords.end();

    while (iter != vWords.begin())
    {
        --iter;
        S2 += *iter + " ";
    }
      S2=S2.substr(0, S2.length() - 1);
      return S2;
}



void OperationsOnString::PrintFirstLetterOfEachWord(string S)
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

string OperationsOnString::UpperFirstLetterOfEachWord(string S)
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

string OperationsOnString::LowerFirstLetterOfEachWord(string S)
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

string OperationsOnString::UpperAllString(string S)
{
    for (short i = 0; i < S.length(); i++)
    {
        S[i] = toupper(S[i]);
    }
    return S;
}

string OperationsOnString::LowerAllString(string S)
{
    for (short i = 0; i < S.length(); i++)
    {
        S[i] = tolower(S[i]);
    }
    return S;
}

char OperationsOnChar::InvertLetterCase(char Char)
{
    return isupper(Char) ? tolower(Char) : toupper(Char);
}

bool OperationsOnChar::IsVowel(char Letter)
{

    Letter = tolower(Letter);
    return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}
