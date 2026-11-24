#include <iostream>
#include <cctype>
#include "InputLib.h"
#include "StrAndCharLib.h"

using namespace std;


void PrintEachWordInString(string S)
{
    string delim = " ";
    cout << "\nYour string wrords are: \n\n";
    short pos = 0;
    string sWord; 
    while ((pos = S.find(delim)) != std::string::npos)
    {
        sWord = S.substr(0, pos);
        if (sWord != "")
            cout << sWord << endl;
        S = S.erase(0, pos + 1);
    }
    if (S != "")
    {
        cout << S << endl;
    }


}



int main()
{

    string S = UserInput::ReadString();
    cout << "\nYour String Words Are: \n\n";
    PrintEachWordInString(S);


    return 0;
}
