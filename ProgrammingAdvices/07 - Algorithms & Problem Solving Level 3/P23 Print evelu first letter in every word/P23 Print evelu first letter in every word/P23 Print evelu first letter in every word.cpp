#include <iostream>
#include <string>
#include "InputLib.h"
using namespace std;

void PrintFirstLetterOfEachWord(string S)
{
    bool isFirstLetter = true;

    cout << "\nFirst letters of this string: \n";

    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] != ' ' && isFirstLetter)
        {
            cout << S[i] << endl;
        }

        isFirstLetter = S[i]==' ' ? true : false;
    }
}

int main()
{
    PrintFirstLetterOfEachWord(User_Input::ReadString());
}
