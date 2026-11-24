#include <iostream>
#include <cctype>
#include "InputLib.h"
#include "StrAndCharLib.h"

using namespace std;


short CountLetter(const string& S, const char& Character, bool Sinsatev = true)
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

char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

bool IsVowel(char Letter)
{

    Letter = tolower(Letter);
    return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}


int main()
{

    char Letter = UserInput::ReadChar();

    
    if (IsVowel(Letter))
    {
        cout << "Yes Letter \'" << Letter << "\' is a vowel\n";
    }
    else
    {
        cout << "No Letter \'" << Letter << "\' is Not a vowel\n";
    }



    return 0;
}
