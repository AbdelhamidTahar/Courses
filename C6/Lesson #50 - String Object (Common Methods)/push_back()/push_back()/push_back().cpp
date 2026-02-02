#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S1 = "Abdelhamid Tahar";

    int Add = 0;
    while(Add<10)
    {

        // push_back Method use char as prametar only no string.
        S1.push_back('Y');
        ++Add;
    }

    cout << S1;

}
