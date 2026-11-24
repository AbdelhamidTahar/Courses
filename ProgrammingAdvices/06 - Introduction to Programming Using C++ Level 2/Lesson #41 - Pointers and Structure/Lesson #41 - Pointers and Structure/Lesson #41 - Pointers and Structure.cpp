// Example program
#include <iostream>
#include <string>
using namespace std;

struct Person
{
    string FirstName;
    string LastName;
    unsigned short Age = 0;
    char Sex;
};




int main()
{

    Person Person1;
    Person* PointerPerson = &Person1;

    Person1.FirstName = "Abdelhamid";
    Person1.LastName = "Tahar";
    Person1.Age = 23;
    Person1.Sex = 'M';

    cout << "Address Of Struct: " << &Person1 << endl;
    cout << endl;

    cout << "Value Of Struct: " << endl;
    cout << endl;
    cout << "First Name: " << Person1.FirstName << endl;
    cout << "Last Name : " << Person1.LastName << endl;
    cout << "Age       : " << Person1.Age << endl;
    cout << "Sex       : " << Person1.Sex << endl;


    cout << "Value Of Pointer: " << PointerPerson << endl;
    cout << "Address Of Pointer: " << &PointerPerson << endl;
    cout << endl;

    cout << "Value Of Struct using Pointer: " << endl;
    cout << "First Name: " << PointerPerson->FirstName << endl;
    cout << "Last Name : " << PointerPerson->LastName << endl;
    cout << "Age       : " << PointerPerson->Age << endl;
    cout << "Sex       : " << PointerPerson->Sex << endl;



    return 0;

}