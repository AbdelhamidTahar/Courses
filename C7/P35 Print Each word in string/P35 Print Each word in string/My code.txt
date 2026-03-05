#include <iostream>
#include <cctype>
#include "InputLib.h"
#include "StrAndCharLib.h"

using namespace std;

short FindFirstLetterOfEachWord(const string &S,const short &EndIndex)
{
    bool isFirstLetter = true;

    for (short i = EndIndex; i < S.length(); i++)
    {
        if ((S[i] != ' ' && S[i] != '\t') && isFirstLetter)
        {
            return i;
        }

        isFirstLetter = (S[i] == ' ' || S[i] == '\t') ? true : false;
    }
    return -1;
}

short FindEndLetterOfEachWord(const string& S,const short & StartIndex)
{
   

    for (short i = StartIndex; i < S.length(); i++)
    {
        if (S[i] == ' ' || S[i]=='\t')
        {
            return i - 1;
        }

    }
    return S.length() - 1;
   
}

void PrintEachWordInString(const string &S)
{
    


    short StartWord = 0;
    short EndWord = -1;

    while (EndWord != S.length() - 1)

    {
        StartWord = FindFirstLetterOfEachWord(S, EndWord + 1);
        if (StartWord != -1)
        {
            EndWord = FindEndLetterOfEachWord(S, StartWord);

            for (short i = StartWord; i <= EndWord; i++)
            {
                cout << S[i];
            }
            cout << endl;
        }
        else
        {
            break;
        }
    }

}



int main()
{

    string S = UserInput::ReadString();
    cout << "\nYour String Words Are: \n\n";
    PrintEachWordInString(S);

    return 0;
}
