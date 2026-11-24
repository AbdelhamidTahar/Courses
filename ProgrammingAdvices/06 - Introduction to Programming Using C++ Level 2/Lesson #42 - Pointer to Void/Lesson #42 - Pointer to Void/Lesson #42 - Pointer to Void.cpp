#include <iostream>
using namespace std;

int main()
{
    int Number = 55514;
    cout << "Value of Address Number Without Pointer: " << &Number << endl;
    cout << "Value of Number Without Pointer: " << Number << endl;

    void *Ptr = &Number;
    cout << "Value of Pointer : " << Ptr << endl;
    cout << "Address Pointer : " << &Ptr << endl;
    cout << "Value of Pointer To Pointing: " << *(static_cast<int*>(Ptr)) << endl;

    float FF = 543.43334;
    cout << endl;
    cout << "Value of Address FF Without Pointer: " << &FF << endl;
    cout << "Value of FF Without Pointer: " << FF << endl;

    Ptr = &FF;
    cout << "Value of Pointer : " << Ptr << endl;
    cout << "Address Pointer : " << &Ptr << endl;
    *(static_cast<float*>(Ptr)) = 78.9;
    cout << "Value of Pointer To Pointing: " << *(static_cast<float*>(Ptr))<< endl;

}
