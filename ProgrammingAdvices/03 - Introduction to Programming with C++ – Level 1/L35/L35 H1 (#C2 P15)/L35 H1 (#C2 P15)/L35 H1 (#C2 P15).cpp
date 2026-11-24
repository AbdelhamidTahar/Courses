#include <iostream>
using namespace std;

float Rectangle_Area(float a, float b)
{
    return a * b;
}
int main()
{
    float a, b;
    cout << "Please  enter the value of A?\n";
    cin >> a;
    cout << "Please enter the value of B\n";
    cin >> b;

    cout << Rectangle_Area(a, b);


    return 0;
}