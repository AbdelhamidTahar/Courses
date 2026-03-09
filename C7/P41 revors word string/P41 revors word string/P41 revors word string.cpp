#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include "InputLib.h"


vector<string>SplitString(string S, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S.find(Delim)) != std::string::npos)
    {
        sWord = S.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S.erase(0, pos + Delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S != "")
    {
        vString.push_back(S); // it adds last word of the string.
    }
    return vString;
}

string ReverseWordsInString(string S)
{
    vector<string> vWords = SplitString(S, " ");
    string S2 = "";
    vector<string>::iterator iter = vWords.end();

    while (iter != vWords.begin())
    {
        --iter;
        S2 += *iter + " ";
    }
    return  S2.substr(0, S2.length() - 1);
}


int main()
{
    string S1 = UserInput::ReadString();
    cout << "\n\nString after reversing words:";
    cout << "\n" << ReverseWordsInString(S1);

}
