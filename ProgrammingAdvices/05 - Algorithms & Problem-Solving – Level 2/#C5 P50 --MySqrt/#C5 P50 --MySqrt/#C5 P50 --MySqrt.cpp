#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float Number = 0;

    cout << "Please enter a number?";
    cin >> Number;

    return Number;
}



float MySqrt(float Number)
{
    return (pow(Number, 0.5));
}

int main()
{

    float Number = ReadNumber();
    cout << "My SQRT Resalt: " << MySqrt(Number) << endl;
    cout << "C++ SQRT Resalt: " << sqrt(Number);



    return 0;
}