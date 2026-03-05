#include <iostream>
#include <cctype>
#include "InputLib.h"
#include "StrAndCharLib.h"

using namespace std;





void PrintVowels(const string& S)
{
    cout << "\nVowels in string are: ";
    for (short i = 0; i < S.length(); i++)
    {
        if (OperationsOnChar::IsVowel(S[i]))
            cout << S[i] << "    ";
    }
   
}

int main()
{

    string S = UserInput::ReadString();


    
    PrintVowels(S);


    return 0;
}
