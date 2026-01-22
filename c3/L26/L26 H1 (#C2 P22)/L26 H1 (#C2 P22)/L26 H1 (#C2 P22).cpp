#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    float a,b, area;
    const float pi = 3.14159;

    cout << "Please enter the valu of A?\n";
    cin >> a;

    cout << "Please enter the valu of B?\n";
    cin >> b;


    
    area = pi * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
    area = floor(area);

    cout << area << "\n";


    return 0;
}
