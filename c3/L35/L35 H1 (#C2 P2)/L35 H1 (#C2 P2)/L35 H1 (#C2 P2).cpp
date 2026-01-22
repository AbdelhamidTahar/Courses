#include <iostream>
#include <string>
using namespace std;

void print_name()
{
    string name;

    cout << "Please enter your name" << endl;
    getline(cin, name);
    cout << name << endl;
}

int main()
{

    print_name();

    return 0;
}