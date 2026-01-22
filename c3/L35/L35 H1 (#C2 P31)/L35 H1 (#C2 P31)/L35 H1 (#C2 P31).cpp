//31
#include <iostream>
using namespace std;


void power()
{
    int number, a, b, c;

    cout << "Please enter the value of number" << endl;
    cin >> number;

    a = number * number;
    b = number * number * number;
    c = number * number * number * number;

    cout << "\n" << a << "\n";
    cout << b << "\n";
    cout << c << endl;

}
int main()
{
    power();

    return 0;
}