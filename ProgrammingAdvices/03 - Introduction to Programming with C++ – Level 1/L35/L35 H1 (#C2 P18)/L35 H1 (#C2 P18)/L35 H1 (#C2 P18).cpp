#include <iostream>
#include <cmath>
using namespace std;

float circle_area(float r)
{
    const float pi = 3.14159;


    return pi * pow(r, 2);
}

int main()
{
    float r;
    cout << "Please enter the value of R" << endl;
    cin >> r;
    cout << circle_area(r) << endl;
}