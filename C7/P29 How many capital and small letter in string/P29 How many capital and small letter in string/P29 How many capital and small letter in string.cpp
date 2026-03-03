#include <iostream>
#include <cctype>
#include "InputLib.h"
#include "StrAndCharLib.h"
using namespace std;








int main()
{
    string S = UserInput::ReadString();

    cout << "\n\nMethod 1\n\n";
    cout << "\nString Length = "<< S.length()<<"\n";
    cout << "\nCapital Letter Count = " <<OperationsOnString:: CountCapitalLetters(S) << "\n";
    cout << "\Small Letter Count = " <<OperationsOnString:: CountSmallLetters(S) << "\n";


    cout << "\n\nMethod 2\n\n";
    cout << "\nString Length = " <<OperationsOnString::CountLetters(S) << "\n";
    cout << "\nCapital Letter Count = " << OperationsOnString::CountLetters(S, OperationsOnString::enWhatToCount::CapitalLetters) << "\n";
    cout << "\Small Letter Count = " << OperationsOnString::CountLetters(S, OperationsOnString::enWhatToCount::SmallLetters) << "\n";


    return 0;
}
