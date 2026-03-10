#include <iostream> 
#include <string> 
#include <cctype> 
#include <vector> 
#include "InputLib.h" 
using namespace std;

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

string LowerAllString(string S)
{
    for (short i = 0; i < S.length(); i++)
    {
        S[i] = tolower(S[i]);
    }
    return S;
}

vector<string> ChangWord(vector<string>vString, string Word, string WordToReplace, bool Sensitive = true)
{

    vector<string>::iterator iter = vString.end();

    string TempString = "";
    while (iter != vString.begin())
    {
        --iter;
        TempString = *iter;

        if (Sensitive == false)
        {
            Word = LowerAllString(Word);
            TempString = LowerAllString(TempString);
        }

        if (TempString == Word)
        {
            *iter = WordToReplace;
        }
    }


    return vString;
}

string JoinString(vector<string>vString, string Delim)
{
    string S1 = "";

    for (string& Elemnet : vString)
    {
        S1 = S1 + Elemnet + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());

}

string ReplaceWordInString(string S1, string Delim, string Word, string WordToReplace, bool Sensitive = true)
{
    vector<string>vS;
    vS = SplitString(S1, Delim);
    vS = ChangWord(vS, Word, WordToReplace, Sensitive);

    return JoinString(vS, Delim);
}




int main()
{
    // string S1 = UserInput::ReadString(); 
    cout << "\nOriginal String:\n"
        << "hello ada i'm from jorden i like jorden a lot do you like jorden ?";

    cout << "\n\nReplace with match case: ";
    cout << "\n" << ReplaceWordInString
    ("hello ada i'm from jorden i like jorden a lot do you like jorden ?", " ", "Jorden", "USA");



    cout << "\n\nReplace with dont match case: ";
    cout << "\n" << ReplaceWordInString
    ("hello ada i'm from jorden i like jorden a lot do you like jorden ?", " ", "Jorden", "USA", false);

    cout << endl;

}

