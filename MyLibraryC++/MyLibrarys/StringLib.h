#pragma once
#include<iostream>
#include<string>
#include<cctype>
using namespace std;


namespace OperationsOnTheArray
{
    void PrintFirstLetterOfEachWord(string S);
    string UpperFirstLetterOfEachWord(string S);
    string LowerFirstLetterOfEachWord(string S);


}
void OperationsOnTheArray::PrintFirstLetterOfEachWord(string S)
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
string OperationsOnTheArray::UpperFirstLetterOfEachWord(string S)
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
string OperationsOnTheArray::LowerFirstLetterOfEachWord(string S)
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
