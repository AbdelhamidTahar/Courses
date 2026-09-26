#include <iostream>
#include "clsDate.h"
using namespace std;

int main()
{
    clsDate D1;
    clsDate D2("77/99/2025");
    clsDate D3(44, 33, 2024);
    clsDate D4(78968, 2023);

    D1.Print();
    D2.Print();
    D3.Print();
    D4.Print();


}
