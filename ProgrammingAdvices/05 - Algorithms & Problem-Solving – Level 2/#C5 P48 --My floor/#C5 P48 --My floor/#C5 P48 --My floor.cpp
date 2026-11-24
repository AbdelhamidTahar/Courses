#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
      float Number = 0;

    cout << "Please enter a number?";
    cin >> Number;

    return Number;
}

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyFloor(float Number)
{
    float FractionsPart = GetFractionPart(Number);

    if (Number == 0)
    {
        return 0;
    }
    else if (Number > 0)
    {
        return int(Number);
    }
    else
    {
        if (FractionsPart == 0)
        {
            return int(Number);
        }
        else
        {
            
            return int(Number)-1;
        }
    }
}

int main()
{

    float Number = ReadNumber();
    cout << "My FLOOR Resalt: " << MyFloor(Number) << endl;
    cout << "C++ FLOOR Resalt: " << floor(Number);



    return 0;
}