#include <iostream>
#include <cctype>
#include "InputLib.h"
#include "StrAndCharLib.h"

using namespace std;





short CountVowels(const string& S)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (OperationsOnChar::IsVowel(S[i]))
            Count++;
    }
    return Count;
}

int main()
{

    string S = UserInput::ReadString();


    cout << "Number Of Vowels is: " << CountVowels(S)<< "\n";



    return 0;
}
