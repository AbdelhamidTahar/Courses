#include <iostream>
using namespace std;

int main()
{
    float loanamount; 

    cout << "Please enter the loan amount you want?\n";
    cin >> loanamount;

    int howmanymonths;

    cout << "please enter how many months you want to repay the loan?\n";
    cin >> howmanymonths; 

    float monthlyinstallment = loanamount / howmanymonths;

    cout << monthlyinstallment;

    return 0;
}

