#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector <int> vNumbers{ 432,56,2,65,2,6, };
    vector <int>::iterator iter;


    for (iter = vNumbers.begin(); iter != vNumbers.end(); iter++)
    {
        *iter = ++ * iter;
        
        cout <<  "Value :" << *iter << " \n";
    }
    
}
