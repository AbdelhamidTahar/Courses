#include <iostream>
using namespace std;

class clsAddress
{
private:
	string _Country;
	string _City;
	string _Street;
	string _PObox;
	string _ZipCode;

public:
	//Constructors1
	clsAddress(string Country, string City, string Street, string PObox, string ZipCode)
	{
		_Country = Country;
		_City = City;
		_Street = Street;
		_PObox = PObox;
		_ZipCode = ZipCode;
	}

	//Constructors2
	clsAddress()

	{
		_Country = "Nothing";
		_City = "Nothing";
		_Street = "Nothing";
		_PObox = "Nothing";
		_ZipCode = "Nothing";
	}
			
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
		_Country = City;
	}
	string City()
	{
		return _City;
	}

	void SetStreet(string Street)
	{
		_Street = Street;
	}
	string Street()
	{
		return _Street;
	}

	void SetPObox(string PObox)
	{
		_PObox = PObox;
	}
	string PObox()
	{
		return _PObox;
	}

	void SetZipCode(string ZipCode)
	{
		_ZipCode = ZipCode;
	}
	string ZipCode()
	{
		return _ZipCode;
	}

	void PrintAddress()
	{
		cout << "\n-----------------\n";

		cout << "Country: " << _Country << endl;
		cout << "City: " << _City << endl;
		cout << "Street: " << _Street << endl;
		cout << "PObox: " << _PObox << endl;
		cout << "Zip Code: " << _ZipCode << endl;

		cout << "\n-----------------\n";

	}


};

int main()
{

	clsAddress Address1("Algeara", "Tebessa", "AirPort", "152243", "12000");
	Address1.PrintAddress();

	clsAddress Address2;
	Address2.PrintAddress();

	return 0;
}