#include <iostream>
using namespace std;

int main()
{
    int n = 200;
    int f = 300;
    int& x = n;
    //int& x = f;  wrong because x must by alias one varible only not multi

    int* p;


    p = &n;
    p = &f;

    
}
