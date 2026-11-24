#include <iostream>
#include <cctype>
#include "InputLib.h"
using namespace std;

char ReadChar()
{
    cout << "Please Enter Your Char: \n";
    char Character;
    cin >> Character;
    return Character;
}

char InvertLetterCase(char Char)
{
    return isupper(Char) ? tolower(Char) : toupper(Char);
}



int main()
{
    char Character;

    Character = ReadChar();

    Character = InvertLetterCase(Character);
    cout << "\nChar After Inverting Case\n";
    cout << Character << "\n";


	return 0;
}
