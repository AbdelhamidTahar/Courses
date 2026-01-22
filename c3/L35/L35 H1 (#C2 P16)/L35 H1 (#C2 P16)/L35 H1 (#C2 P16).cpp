#include <iostream>
#include<cmath>
using namespace std;

float Rectangle_Area(float a, float d)
{
    return a * sqrt(pow(d, 2) - pow(a, 2));
}
int main()
{
    float a, d;
    cout << "Please  enter the value of A?\n";
    cin >> a;
    cout << "Please enter the value of D\n";
    cin >> d;

    cout << Rectangle_Area(a, d);


    return 0;
}