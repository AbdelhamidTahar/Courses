#include <iostream>
#include <cmath>
using namespace std;


float ciecle_area(float a, float b, float c)
{
    const float pi = 3.14159;
    float p = (a + b + c) / 2;

    return pi * pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2);
}

int main()
{
    int a, b, c;

    cout << "Please enter the value of A" << endl;
    cin >> a;

    cout << "Please enter the value of B" << endl;
    cin >> b;

    cout << "Please enter the value of C" << endl;
    cin >> c;

    cout << ciecle_area(a, b, c) << endl;

    return 0;
}