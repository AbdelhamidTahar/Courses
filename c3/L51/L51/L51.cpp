#include <iostream>
using namespace std;

int ReadIntNumberInRangeUsingDoWhile(int From, int To)
{
    int Number;

    do
    {
        cout << "Please enter a number between " << From << " and " << To << "\n";
        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}

int ReadIntNumberInRangeUsingWhile(int From, int To)
{
    int Number;

    cout << "Please enter a number between " << From << " and " << To << "\n";
    cin >> Number;

    while (Number < From || Number > To)
    {
        cout << "Please enter a number between " << From << " and " << To << "\n";
        cin >> Number;
    }

    return Number;
}

int main()
{

    cout << ReadIntNumberInRangeUsingDoWhile(1, 10) << endl;
    cout << ReadIntNumberInRangeUsingWhile(1, 10) << endl;

    return 0;
}