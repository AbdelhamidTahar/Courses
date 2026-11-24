#pragma once
#include <iostream>
using namespace std;

namespace ScreenEffect
{

    enum enColor {Red=1,Green=2,Blue=3, White = 4, Black = 5 , Yellow = 6 , Gray = 7};

    void ResetScreen()
    {
        system("cls");
        system("color 0F");
    }

    void ColorScreen(enColor ColorScreen)
    {

        switch (ColorScreen)
        {
        case enColor::Red:
        {
            system("color 4F");
            break;
        }
        case enColor::Green:
        {
            system("color 2F");
            break;
        }
        case enColor::Blue:
        {
            system("color 1F");
            break;
        }
        case enColor::White:
        {
            system("color F0");
            break;
        }
        case enColor::Black:
        {
            system("color 0F");
            break;
        }
        case enColor::Yellow:
        {
            system("color 60");
            break;
        }
        case enColor::Gray:
        {
            system("color 80");
            break;
        }
        
        default:
        {
            system("color 0F");
            break;
        }

        }
    }


}

namespace SoundEffect
{
    void Ring()
    {
        cout << "\a";
    }
}