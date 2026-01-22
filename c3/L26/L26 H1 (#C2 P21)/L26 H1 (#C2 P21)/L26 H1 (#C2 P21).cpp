#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    float l, area;
    const float pi = 3.14159;

    cout << "Please enter the valu of D?\n";
    cin >> l;

    area = pow(l, 2) / (4 * pi);
    area = floor(area);

    cout << area << "\n";


    return 0;
}
