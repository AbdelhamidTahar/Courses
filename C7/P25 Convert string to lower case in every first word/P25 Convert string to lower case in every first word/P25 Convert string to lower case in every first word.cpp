#include <iostream>
#include <string>
#include <cctype>
#include "InputLib.h"
using namespace std;

string LowerFirstLetterOfEachWord(string S)
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

int main()
{
    string Text = User_Input::ReadString();

    cout << "\nString after conversion:\n";
    Text = LowerFirstLetterOfEachWord(Text);
    cout << Text << endl;

}
