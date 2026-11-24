#include <iostream>
#include <cmath>
using namespace std;

float ciecel_area(float a, float b)
{
    const float pi = 3.14159;
    return pi * ((pow(b, 2)) / 4) * ((2 * a - b) / (2 * a + b));
}

int main()
{
    float a, b;

    cout << "Please enter the value of A\n";
    cin >> a;

    cout << "Please enter the value of B\n";
    cin >> b;

    cout << ciecel_area(a, b);

    return 0;
}