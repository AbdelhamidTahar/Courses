#include <iostream>
using namespace std;

class clsPerson
{
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _FullName;
	string _Email;
	string _Phone;

public:
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_FullName = FullName();
		_Email = Email;
		_Phone = Phone;
	}

	int ID()
	{
		return _ID;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string FirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string LastName()
	{
		return _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string Email()
	{
		return _Email;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string Phone()
	{
		return _Phone;
	}

	void SendEmail(string Subjct, string Body)
	{
		cout << "\nThe following Message sent Successfully to email: " << _Email << endl;
		cout << "Subjct: " << Subjct << endl;
		cout << "Body: " << Body << endl;
	}

	void SendSMS(string Body)
	{
		cout << "\nThe following Message sent Successfully to Phone: " << _Phone << endl;
		cout << Body << endl;
	}

	void Print()
	{
		cout << "\nInfo\n";

		cout << "-----------------------------\n";
		cout << "ID: " << _ID << endl;
		cout << "FirstName: " << _FirstName << endl;
		cout << "LastName: " << _LastName << endl;
		cout << "FullName: " << _FullName << endl;
		cout << "Email: " << _Email << endl;
		cout << "Phone: " << _Phone << endl;
		cout << "-----------------------------\n";


	}
};

int main()
{
	clsPerson Person1(10, "Abdelhamid", "TAHAR", "taharabdalhamid12@gmail.com", "0696376164");
	Person1.Print();
	Person1.SendEmail("HI", "THIS IS JUST TEST");
	Person1.SendSMS("THIS IS JUST SMS TEST GOOD BYE.");
}