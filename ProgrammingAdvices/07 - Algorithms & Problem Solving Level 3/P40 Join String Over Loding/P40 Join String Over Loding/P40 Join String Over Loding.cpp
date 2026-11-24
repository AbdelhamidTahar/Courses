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

string JoinString(string arrString[],short arrLengh, string Delim)
{
    string S1 = "";

    for (short i = 0; i < arrLengh;i++)
    {
        S1 = S1 + arrString[i] + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());

}



int main()
{
    vector<string>S = { "abdelhamid","aymen","ali" };
    cout << "\nVector after join: \n";
    cout << JoinString(S, ", ");

    string arrString[]= { "abdelhamid","aymen","ali" };
    cout << "\nArray after join: \n";
    cout << JoinString(arrString,3, ", ");

}

