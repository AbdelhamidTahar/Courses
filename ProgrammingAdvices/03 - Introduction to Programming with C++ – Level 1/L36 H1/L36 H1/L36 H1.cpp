#include <iostream>
using namespace std;

int x = 100;
int z = 200;

void my()
{
    int x = 99;
    cout << "value of  X is: " << x << "\n";
    int w = ::x++;
    cout << "value of W is: " << w << "\n";
    cout << "value of GLOBAL X is: " << ::x << "\n";
    w = ++::x;
    cout << "value of W is: " << w << "\n";
    cout << "value of GLOBAL X is: " << ::x << endl;
}

int main()
{

    my();

    int x = 1;

    cout << "value of MAIN X is: " << x << "\n";
    x = ::x;
    ::x = ++::x;
    cout << "value of GLOBAL X is: " << ::x << "\n";
    cout << "value of MAIN X is: " << x << endl;
    cout << ++::z << endl;


    return 0;
}
