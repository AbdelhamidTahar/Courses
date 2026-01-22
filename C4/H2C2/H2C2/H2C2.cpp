#include <iostream>
#include <string>

using namespace std;

string ReadName()
{
    string Name;
    cout << "Please enter your Name" << endl;
    getline(cin, Name);
    return Name;
}

void PrintName(string Name)
{
    cout << "\nYour Name Is: " << Name << endl;
}

int main()
{

    PrintName(ReadName());

    return 0;
}