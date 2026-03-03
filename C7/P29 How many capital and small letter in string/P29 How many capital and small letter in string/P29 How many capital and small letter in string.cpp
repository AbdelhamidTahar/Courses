#include <iostream>
#include <cctype>
#include "InputLib.h"
using namespace std;

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

short CountLetters(const string &S, enWhatToCount WhatToCount = enWhatToCount::All)
{
    short Count = 0;

    if (WhatToCount == enWhatToCount::All )
    {
        return S.length();
    }

    for(short i = 0 ; i < S.length();i++)
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

 short CountCapitalLetters(const string& S)
{
    short Count = 0;
    for ( short i = 0; i < S.length(); i++)
    {
       if (isupper(S[i]))
       {
           Count++;
       }
    }
    return Count;
}

 short CountSmallLetters(const string& S)
{
    short Count = 0;
    for ( short i = 0; i < S.length(); i++)
    {
        if (islower(S[i]))
        {
            Count++;
        }
    }
    return Count;
}





int main()
{
    string S = UserInput::ReadString();

    cout << "\n\nMethod 1\n\n";
    cout << "\nString Length = "<< S.length()<<"\n";
    cout << "\nCapital Letter Count = " << CountCapitalLetters(S) << "\n";
    cout << "\Small Letter Count = " << CountSmallLetters(S) << "\n";


    cout << "\n\nMethod 2\n\n";
    cout << "\nString Length = " << CountLetters(S) << "\n";
    cout << "\nCapital Letter Count = " << CountLetters(S, enWhatToCount::CapitalLetters) << "\n";
    cout << "\Small Letter Count = " << CountLetters(S, enWhatToCount::SmallLetters) << "\n";


    return 0;
}
