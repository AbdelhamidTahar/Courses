#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S1 = "Abdelhamid Tahar";



    // find() Method use char or string as prametar.
    // if find method fined what is you do you want he's return the firs index in string do you want.
    // if find method does'n find the string or char you want he's return along number(not find). 
    if (S1.find("Thahero") == S1.npos);
    {
        cout << "Sorry we does not find char\n";
    }
   
    cout << S1.find("Tahar") << endl;


    cout << S1<< endl;

    return 0;

}
