#include <iostream>
#include <cmath>
using namespace std;

float cicle_area(float l)
{

    const float pi = 3.14159;

    return pow(l, 2) / (4 * pi);
}

int main()
{

    float l;

    cout << "Please enter the value of L" << endl;
    cin >> l;
    cout << cicle_area(l);


    return 0;
}