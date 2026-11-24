#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S1 = "Abdelhamid Tahar";

    for (int i = 0; i <= 10; i++)
    {
        //append Method use only Stind as parametar.
        cout << S1.append(" TT" + to_string(i)) << endl;
     
    }
    cout << S1;
}
