#include <iostream>
using namespace std;

void SwapNumbers()
{
    int num1, num2, temp;
    cout << "Please enter the first number" << endl;
    cin >> num1;

    cout << "Please enter the second number" << endl;
    cin >> num2;
    cout << "\n";

    cout << num1 << "\n";
    cout << num2 << "\n\n";

    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << num1 << "\n";
    cout << num2 << endl;

}

int main()
{
    SwapNumbers();

    return 0;
}