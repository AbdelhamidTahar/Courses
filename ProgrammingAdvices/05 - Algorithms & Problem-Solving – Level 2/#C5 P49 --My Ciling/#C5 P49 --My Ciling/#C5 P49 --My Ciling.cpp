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

int Myceil(float Number)
{
    float FractionsPart = GetFractionPart(Number);
    
    if (abs(FractionsPart) > 0)
    {
        if (Number > 0)
            return Number + 1;
        else
            return int(Number);

    }
    else
    {
        return int(Number);
    }
  
}

int main()
{

    float Number = ReadNumber();
    cout << "My CEIL Resalt: " << Myceil(Number) << endl;
    cout << "C++ CEIL Resalt: " << ceil(Number);



    return 0;
}