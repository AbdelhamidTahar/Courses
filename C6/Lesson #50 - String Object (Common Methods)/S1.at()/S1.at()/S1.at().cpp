#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S1 = "Abdelhamid Tahar";

    for (int i =0 ; i <= S1.length();i++)
    {
        try
        {
            cout << S1.at(i) << endl;
        }
        catch (...)
        {
            cout << "Not Found";
        }
    }
}
