#include <iostream>
#include <string>

using namespace std;
float ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
float MonthlyInstallment(float LoanAmount, float HowManyMonths)
{
    return LoanAmount / HowManyMonths;
}
int main()
{
    float LoanAmount = ReadPositiveNumber("Please Enter Loan Amount?");

    float HowManyMonths = ReadPositiveNumber("How Many Months?");

    cout << "\nMonthly Installment = " << MonthlyInstallment(LoanAmount, HowManyMonths) << endl;

    return 0;
}