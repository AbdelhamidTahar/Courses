#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    float d, area;
    const float pi = 3.14159;

    cout << "Please enter the valu of D?\n";
    cin >> d; 

    area = (pi * pow(d, 2)) / 4;
    area = ceil(area);

    cout << area<< "\n";

    
    return 0;
}
