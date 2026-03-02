#include <iostream>
#include <cctype>
#include "InputLib.h"
using namespace std;



char InvertLetterCase(char Char)
{
    return isupper(Char) ? tolower(Char) : toupper(Char);
}


string InvertAllStringLettersCase(string S)
{
    for (short i = 0; i < S.length(); i++)
    {
        S[i] = InvertLetterCase(S[i]);
    }
    return S;
}


int main()
{
    string S;

    S = UserInput::ReadString();

    S = InvertAllStringLettersCase(S);
    cout << "\String After Inverting Case\n";
    cout <<"\n" << S << "\n";


    return 0;
}
