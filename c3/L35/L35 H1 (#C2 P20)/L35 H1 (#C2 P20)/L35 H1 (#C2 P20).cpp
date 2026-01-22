#include <iostream>
#include <cmath>
using namespace std;

float cicle_area(float a)
{
    const float pi = 3.14159;

    return (pi * pow(a, 2)) / 4;
}

int main()
{
    float a;
    cout << "Please enter the value of A\n";
    cin >> a;

    cout << cicle_area(a);

    return 0;
}