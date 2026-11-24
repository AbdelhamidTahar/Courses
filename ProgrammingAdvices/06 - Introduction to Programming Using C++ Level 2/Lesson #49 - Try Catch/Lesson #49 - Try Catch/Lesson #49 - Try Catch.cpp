#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vNumbers{ 543,543,543,543,543 };

    //cout << vNumbers.at(10); // exceptional errour

    try
    {

        //The instruction that you suspect
        // will cause an exception error should be placed in the try field 
        // so that if an exception error does occur,
        // the program does not crash.
        cout << vNumbers.at(654);

    }
    catch (...)
    {
        //Here we provide instructions for handling exception errors 
        // if they occur due to the instruction within the try command.
        cout << "Sorry Not Found Index ";
        cout << "Sorry Not Found Index ";
        cout << "Sorry Not Found Index ";
    }

    return 0;
}
