#pragma once
#include<iostream>
#include<string>
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
    short CountLetter(const string& S, const char& Letter);
   

}

namespace OperationsOnChar
{
    char InvertLetterCase(char Char);
}

short OperationsOnString::CountLetter(const string& S, const char& Letter)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] == Letter)
        {
            Count++;
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
