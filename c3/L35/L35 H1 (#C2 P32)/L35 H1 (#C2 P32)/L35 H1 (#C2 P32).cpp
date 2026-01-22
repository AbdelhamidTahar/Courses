//32
#include <iostream>
#include <cmath>
using namespace std;


float power(float number, int m)
{

    return pow(number, m);
}
int main()
{
    float number;
    int m;

    cout << "Please enter the value of number ?" << endl;
    cin >> number;

    cout << "Please enter the value of power ?" << endl;
    cin >> m;

    cout << power(number, m) << endl;

    return 0;
}