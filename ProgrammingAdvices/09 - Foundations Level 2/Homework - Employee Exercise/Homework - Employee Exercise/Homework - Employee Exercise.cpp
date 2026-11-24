#include <iostream>
using namespace std;


class clsEmployee
{
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;
	double _Salary;
	string _Department;


public:

	clsEmployee
	(
		int ID, string FirstName, string LastName,
		string Title, string Email, string Phone,
		double Salary, string Department
	)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Email = Email;
		_Phone = Phone;
		_Salary = Salary;
		_Department = Department;
	}

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	//Property Set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	//Propertu Get
	string FirstName()
	{
		return _FirstName;
	}

	//Property Set
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	//Propertu Get
	string LastName()
	{
		return _LastName;
	}

	//Property Set
	void SetTitle(string Title)
	{
		_Title = Title;
	}
	//Propertu Get
	string Title()
	{
		return _Title;
	}

	//Property Set
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	//Propertu Get
	string Email()
	{
		return _Email;
	}


	//Property Set
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	//Propertu Get
	string Phone()
	{
		return _Phone;
	}

	//Property Set
	void SetPhone(double Salary)
	{
		_Salary = Salary;
	}
	//Propertu Get
	double Salary()
	{
		return _Salary;
	}

	//Property Set
	void SetDepartment(string Department)
	{
		_Department = Department;
	}
	//Propertu Get
	string Department()
	{
		return _Department;
	}


	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email;
		cout << "\nSubject: " << Subject;
		cout << "\nBody: " << Body << endl;
	}

	void SendSMS(string TextMessage)
	{
		cout << "\nThe following SMS sent successfully to phone: "
			<< _Phone;
		cout << "\n" << TextMessage << endl;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nID : " << _ID;
		cout << "\nFirstName : " << _FirstName;
		cout << "\nLastName  : " << _LastName;
		cout << "\nFull Name : " << FullName();
		cout << "\nTitle     : " << FullName();
		cout << "\nEmail     : " << _Email;
		cout << "\nPhone     : " << _Phone;
		cout << "\nSalary    : " << _Salary;
		cout << "\nDepartment: " << _Department;
		cout << "\n___________________\n";
	}
};



int main()
{
	clsEmployee Employee1
	(
		1, "abdelhamid", "LastName", "Jouner",
		"taharabdalhamid12@gmail.com",
		"0555174615", 19000, "B"
	);

	Employee1.SendEmail("Hi", "How are you?");
	Employee1.SendSMS("How are You?");
	Employee1.Print();
	return 0;
}




