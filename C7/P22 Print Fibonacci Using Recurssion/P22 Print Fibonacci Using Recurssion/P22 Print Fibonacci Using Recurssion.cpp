#include <iostream>
using namespace std;


void PrintFibonacciUsingRecurssion(int Number, int Prev2, int Prev1)
{
    int Freq = Prev2 + Prev1;

    if(Number > 0)
    {
        Prev2 = Prev1;
        Prev1 = Freq;
        cout << Freq << "\t";
        PrintFibonacciUsingRecurssion(Number - 1, Prev2, Prev1);
    }
    

}
int main()
{
    PrintFibonacciUsingRecurssion(10, 1, 0);
}