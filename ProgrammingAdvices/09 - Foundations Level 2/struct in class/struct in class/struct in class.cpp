#include <iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	struct Address
	{
		string Country;
		string City;
		string Street;
		string NumberOfHouse;
	};



public:
	Address Adrress;

	void SetCountry(string Country)
	{
		Adrress.Country = Country;
	}
	string Country()
	{
		return Adrress.Country;
	}



	clsPerson()
	{
		_FirstName = "abdelhamid";
		_LastName = "TAHAR";
		Adrress.Country = "ALGERIA";
		Adrress.City = "TEBESSA";
		Adrress.Street = "AIR PORT";
		Adrress.NumberOfHouse = "245F55TY";
	}

	void Print()
	{
		cout << "Full Name: " << _FirstName + " " + _LastName << endl;

		cout << "\nAddress: " << endl;
		cout << "Country: " << Adrress.Country << endl;
		cout << "City: " << Adrress.City << endl;
		cout << "Street: " << Adrress.Street << endl;
		cout << "Number Of House: " << Adrress.NumberOfHouse << endl;

	}

};


int main()
{
	clsPerson Person1;


	Person1.Print();

	Person1.SetCountry("GERMANY");
	cout << Person1.Country()<< endl<< endl;

	Person1.Print();
}