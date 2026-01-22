#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

    cout << "After swap inside fuction A=" << a << " ,B=" << b << endl;
}

int main()
{
    int a, b;

    cout << "Please enter the value of A" << endl;
    cin >> a;

    cout << "Please enter the value of B" << endl;
    cin >> b;

    cout << "Before swap A=" << a << ", B=" << b << endl;

    swap(a, b);

    cout << "After swap inside main the fuction A=" << a << " ,B=" << b << endl;
   
    return 0;
}