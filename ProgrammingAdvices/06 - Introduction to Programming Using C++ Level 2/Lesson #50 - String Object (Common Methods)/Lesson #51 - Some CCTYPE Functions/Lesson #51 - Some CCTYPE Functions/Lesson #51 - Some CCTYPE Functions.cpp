#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char x,y,z,j ;

    x = 'w';
    cout << "The Value of x: " << x << endl;
    x = toupper(x);
    cout << "The value of x after change from lower to upper: " << x << endl;
    cout << endl;


    y = 'L';
    cout << "The Value of y: " << y << endl;
    y = tolower(y);
    cout << "The value of y after change from upper to lower: " << y << endl;
    cout << endl;


    z = '0';
    cout << "The Value of z: " << z << endl;
    cout << "is The value of z is digit ?: " << isdigit(z) << endl;
    cout << endl;


    j = ')';
    cout << "The Value of j: " << j << endl;
    cout << "is The value of j symbol ?: " << ispunct(j) << endl;

}
