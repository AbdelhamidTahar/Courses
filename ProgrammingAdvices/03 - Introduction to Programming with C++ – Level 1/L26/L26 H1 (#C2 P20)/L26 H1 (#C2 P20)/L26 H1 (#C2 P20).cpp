#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    float a, area;
    const float pi = 3.14159;

    cout << "Please enter the valu of D?\n";
    cin >> a;

    area = (pi * pow(a, 2)) / 4;
    area = ceil(area);

    cout << area << "\n";


    return 0;
}
