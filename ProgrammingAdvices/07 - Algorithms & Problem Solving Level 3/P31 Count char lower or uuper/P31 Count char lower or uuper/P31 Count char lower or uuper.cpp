#include <iostream>
#include <cctype>
#include "InputLib.h"

using namespace std;


short CountLetter(const string& S, const char& Character,bool Sinsatev = true)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if(Sinsatev)
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




int main()
{
    string S = UserInput::ReadString();

    cout << endl;

    char Charcter = UserInput::ReadChar();

    cout << "\nLetter '" << Charcter << "' Count = " << CountLetter(S, Charcter);



    cout << "\n\nLetter '" << Charcter << "'  '"<< InvertLetterCase(Charcter) <<  "' Count = " << CountLetter(S, Charcter,false);

    return 0;
}
