#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}



string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}


string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
enum eDateFromate 
{
DDslashMMslashYYYY=1,
YYYYslashDDslashMM=2,
MMslashDDslashYYYY=3, 
MMdashDDdashYYYY=4,
DDdashMMdashYYYY=5,
DaycommaMonthcommaYear =6
};

string ConvertDateFormate(string DateString, eDateFromate DateFromate)
{
    if (DateFromate == eDateFromate::DDslashMMslashYYYY)
        return DateString;

    vector<string>DateAsplitString = SplitString(DateString,"/");
    switch (DateFromate)
    {

    case eDateFromate::YYYYslashDDslashMM:
    {
        return DateAsplitString[2] + '/' + DateAsplitString[0] + '/' + DateAsplitString[1];
    }

    case eDateFromate::MMslashDDslashYYYY:
    {
        return DateAsplitString[1] + '/' + DateAsplitString[0] + '/' + DateAsplitString[2];
    }

    case eDateFromate::MMdashDDdashYYYY:
    {
        return DateAsplitString[1] + '-' + DateAsplitString[0] + '-' + DateAsplitString[2];
    }

    case eDateFromate::DDdashMMdashYYYY:
    {
        return DateAsplitString[0] + '-' + DateAsplitString[1] + '-' + DateAsplitString[2];
    }

    case eDateFromate::DaycommaMonthcommaYear:
    {
        return "Day:" + DateAsplitString[0] + ", Month:"+ DateAsplitString[1] + ", Year:" + DateAsplitString[2];
    }

    }
    return DateString;
}

int main()
{

    
        string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
        cout << ConvertDateFormate(DateString, DDslashMMslashYYYY) << endl;
        cout << ConvertDateFormate(DateString, YYYYslashDDslashMM) << endl;
        cout << ConvertDateFormate(DateString, MMslashDDslashYYYY) << endl;
        cout << ConvertDateFormate(DateString, MMdashDDdashYYYY) << endl;
        cout << ConvertDateFormate(DateString, DDdashMMdashYYYY) << endl;
        cout << ConvertDateFormate(DateString, DaycommaMonthcommaYear) << endl;


    system("pause>0");
    return 0;
}
