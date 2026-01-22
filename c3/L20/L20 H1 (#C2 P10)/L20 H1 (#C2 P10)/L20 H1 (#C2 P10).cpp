#include <iostream>
using namespace std;

int main()
{
    float mark1, mark2, mark3, avg;

    cout << "Please enter the first mark\n";
    cin >> mark1;

    cout << "Please enter the sacende mark\n";
    cin >> mark2;

    cout << "Please enter the therd mark\n\n";
    cin >> mark3;

    avg = (mark1 + mark2 + mark3) / 3;
    cout << avg;


    return 0;
}