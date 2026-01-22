#include <iostream>
#include <string>


using namespace std;


struct strInfo
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};


void ReadInfo(strInfo& Info)
{

    cout << "Please enter FirstName?\n";
    cin >> Info.FirstName;


    cout << "Please enter LastName?\n";
    cin >> Info.LastName;


    cout << "Please enter Age?\n";
    cin >> Info.Age;


    cout << "Please enter Phone?\n";
    cin >> Info.Phone;

}


void PrintInfo(strInfo Info)
{


    cout << "\n**********************************\n";


    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;


    cout << "\n**********************************\n";

}


void ReadPersonsInfo(strInfo Persons[2])
{
    ReadInfo(Persons[0]);
    ReadInfo(Persons[1]);
}


void PrintPersonsInfo(strInfo Persons[2])
{
    cout << "\n**********************************\n";


    PrintInfo(Persons[0]);
    PrintInfo(Persons[1]);


}



int main()
{


    strInfo Persons[2];


    ReadPersonsInfo(Persons);
    PrintPersonsInfo(Persons);

    return 0;
}
