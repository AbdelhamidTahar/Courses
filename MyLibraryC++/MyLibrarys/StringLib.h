#pragma once
#include<iostream>
#include<string>
#include<cctype>
using namespace std;


namespace OperationsOnString
{
    void PrintFirstLetterOfEachWord(string S);
    string UpperFirstLetterOfEachWord(string S);
    string LowerFirstLetterOfEachWord(string S);
    string UpperAllString(string S);
    string LowerAllString(string S);
    string InvertAllStringLettersCase(string S);

}

namespace OperationsOnChar
{
    char InvertLetterCase(char Char);
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
