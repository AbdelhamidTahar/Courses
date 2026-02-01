#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector <int> vNumbers{ 54,65,23423 };

    cout << "Vector Value Befor Changein\n";
    for (const int& i : vNumbers)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Change Vector Value Using Rangid Loop And Print\n";
        for (int& i : vNumbers)
        {
            i = 00;
            cout << i << " ";
        }
        cout << endl;

        cout << "Change Vector Value Using Normal index\n";

        vNumbers[0] = 99;
        vNumbers[1] = 99;
        vNumbers[2] = 99;

        cout << "Print Vlaue Vector After  Shang Vector Value Using Normal index\n";
        for (const int& i : vNumbers)
        {
            cout << i << " ";
        }
        cout << endl;


        cout << "Change Vector Value Using .at() \n";

        vNumbers.at(0) = 44;
        vNumbers.at(1) = 44;
        vNumbers.at(2) = 44;
        cout << "Print Vlaue Vector After  Shang Vector Value Using .at()\n";
        for (const int& i : vNumbers)
        {
            cout << i << " ";
        }
        cout << endl;

    return 0;
}