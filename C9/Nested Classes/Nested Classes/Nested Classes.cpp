
#include<iostream>
using namespace std;

class clsPerson {

private:

    class  clsAddress
    {
    private:

        string _AddressLine1;
        string _AddressLine2;
        string _Country;
        string _City;
      
    public:

        void SetCountry(string Country)
        {
            _Country = Country;
        }
        string Country()
        {
            return _Country;
        }

        void SetCity(string City)
        {
            _City = City;
        }
        string City()
        {
            return _City;
        }

        void SetAddressLine1(string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }
        string AddressLine1()
        {
            return _AddressLine1;
        }

        void SetAddressLine2(string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }
        string AddressLine2()
        {
            return _AddressLine2;
        }

        clsAddress(string AddressLine1, string AddressLine2, string Country, string City)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _Country = Country;
            _City = City ;
        }

        void PrintAddress( )
        {
            cout << "\nAddress:\n";
            cout <<"Address Line 1: " << _AddressLine1 << endl;
            cout << "Address Line 2: " << _AddressLine2 << endl;
            cout << "City: " << _City << endl;
            cout << "Country: " << _Country << endl;
        }
    };

public:
    string FullName;
    clsAddress Address;


    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
        :Address(AddressLine1, AddressLine2, Country, City )
    {
        FullName = FullName;

    }



};

int main()

{

    clsPerson Person1("ABDELHAMID ATAHR", "TEBESSA", "TEBESSA", "TEBESSA", "ALGERIA");

    Person1.Address.PrintAddress();
   

    system("pause>0");
    return 0;
}