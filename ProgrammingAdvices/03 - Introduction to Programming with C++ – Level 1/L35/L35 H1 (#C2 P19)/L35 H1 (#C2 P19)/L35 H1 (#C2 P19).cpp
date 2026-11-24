#include <iostream>
#include <cmath>
using namespace std;

float circle_area(float d)
{

    const float pi = 3.14159;


    return (pi * pow(d, 2)) / 4;
}

int main()
{
    float d;

    cout << "Please enter the value of D" << endl;
    cin >> d;
    cout << circle_area(d) << endl;

    return 0;
}