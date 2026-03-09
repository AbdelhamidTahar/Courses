#include <iostream>
#include<vector>

using namespace std;

string JoinString(vector<string>vString, string Delim)
{
    string S1 = "";

    for (string& Elemnet : vString)
    {
        S1 = S1 + Elemnet + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
    
}


int main()
{
    vector<string>S = { "abdelhamid","aymen","ali" };
    cout << "\nVector after join: \n";
    cout << JoinString(S, ", ");;
    
}

