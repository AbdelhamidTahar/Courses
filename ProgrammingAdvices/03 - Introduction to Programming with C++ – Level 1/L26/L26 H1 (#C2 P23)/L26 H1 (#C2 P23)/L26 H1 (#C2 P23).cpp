#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    float a, b, c, p, area;
    const float pi = 3.14159;

    cout << "Please enter the valu of A?\n";
    cin >> a;

    cout << "Please enter the valu of B?\n";
    cin >> b;

    cout << "Please enter the valu of C?\n";
    cin >> c;

    p = (a + b + c) / 2;
    area = pi * pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2);
    area = round(area);

    cout << area << "\n";


    return 0;
}
