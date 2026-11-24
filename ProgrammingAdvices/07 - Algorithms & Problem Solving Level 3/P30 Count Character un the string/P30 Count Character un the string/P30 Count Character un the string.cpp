#include <iostream>
#include <cctype>
#include "InputLib.h"

using namespace std;


short CountLetter(const string& S, const char& Character)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] == Character)
        {
            Count++;
        }
    }
    return Count;
}



int main()
{
    string S = UserInput::ReadString();
    
    cout << endl;
    
    char Charcter = UserInput::ReadChar();

    cout << "\nLetter '" << Charcter << "' Count = " << CountLetter(S, Charcter);

    return 0;
}
