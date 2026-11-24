#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "InputLib.h"
using namespace std;



string ReplaceWordInStringUsingBuiltInFunction(string S1, string
    StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace);
    }

    return S1;

}
    




int main()
{
    string S1 = UserInput::ReadString();
    S1 = ReplaceWordInStringUsingBuiltInFunction(S1,  "Jorden", "USA");
    cout << S1;
 
}
