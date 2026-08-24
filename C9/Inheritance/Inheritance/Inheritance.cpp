#include <iostream>
using namespace std;

class clsPerson
{
private:

	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	//clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
	//{
	//	_ID = ID;
	//	_FirstName = FirstName;
	//	_LastName = LastName;
	//	_Email = Email;
	//	_Phone = Phone;
	//}
	
	//Read Only Property
	int ID()
	{
		return _ID;
	}

	//Property Set
	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	
	//Property Get
	string FirstName()
	{
		return _FirstName;
	}
	
	//Property Set
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	
	//Property Get
	string LastName()
	{
		return _LastName;
	}
	
	//Property Set
	void setEmail(string Email)
	{
		_Email = Email;
	}
	
	//Property Get
	string Email()
	{
		return _Email;
	}
	
	//Property Set
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	
	//Property Get
	string Phone()
	{
		return _Phone;
	}

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}
	
	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nID : " << _ID;
		cout << "\nFirstName: " << _FirstName;
		cout << "\nLastName : " << _LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail : " << _Email;
		cout << "\nPhone : " << _Phone;
		cout << "\n___________________\n";
	}
	
	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email;
		cout << "\nSubject: " << Subject;
		cout << "\nBody: " << Body << endl;
	}
	
	void SendSMS(string TextMessage)
	{
		cout << "\nThe following SMS sent successfully to phone: "	<< _Phone;
		cout << "\n" << TextMessage << endl;
	}
};

class clsEmployee : public clsPerson
{
private:
	string _Title;
	string _Department;
	float _Salary;

public:

	void setTitle(string Title)
	{
		_Title = Title;
	}
	string Title()
	{
		return _Title;
	}

	void setDepartment(string Department)
	{
		_Department = Department;
	}
	string Department()
	{
		return _Department;
	}

	void setSalary(float Salary)
	{
		_Salary = Salary;
	}
	float Salary()
	{
		return _Salary;
	}
};

int main()
{

	clsEmployee Employee1;

	Employee1.setFirstName("abdelhamid");
	Employee1.setLastName("TAHAR");
	Employee1.setPhone("0555174615");
	Employee1.setEmail("taharabdalhamid12@gmail.com");
	Employee1.setTitle("Softwer engineer");
	Employee1.setDepartment("CS");
	Employee1.setSalary(6000);

	Employee1.Print();
	Employee1.SendEmail("TEST", "THIS IS JUST A TEST I'M SORRY ABOUT THAT.\nHAVE A GOOD DAY:)\n");
	Employee1.SendSMS
	("HI, THERE I'M REALY SICK TODAY I'M GO TO THE DOCTOR TODAY I'M SOORY I CAN'T WORK TODAY:(\n");

	return 0;
}