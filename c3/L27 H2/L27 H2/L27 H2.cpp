#include <iostream>
using namespace std;

struct address
{
	string country;
	string city;
	string street;
	string numberofhouse_oraprtment;
	unsigned short numberofpost;
};

struct salary
{
	float Mothlysalary;
	float yearlysalary ;
};

struct contactinfo
{
	string facebook;
	string instagram;
	string likedn;
	string website;
	unsigned int phonenumber;
	unsigned int homephonenumber;
};

struct person
{
	string name;
	unsigned short age;
	char gender;
	bool ismarried;
	address addressofperson;
	salary salaryofperson;
	contactinfo contactofperson;
};



int main()
{

	person person1;

	cout << "please enter your name? \n";
	cin >> person1.name;
	cout << "please enter your age? \n";
	cin >> person1.age;
	cout << "please enter your gender? \n";
	cin >> person1.gender;
	cout << "are you married if yes enter 1 if no enter 0 ? \n";
	cin >> person1.ismarried;
	cout << "please enter your country? \n";
	cin >> person1.addressofperson.country;
	cout << "please enter your city? \n";
	cin >> person1.addressofperson.city;
	cout << "please enter your number of post? \n";
	cin >> person1.addressofperson.numberofpost;
	cout << "please enter your  street? \n";
	cin >> person1.addressofperson.street;
	cout << "please enter your number of house/apartment? \n";
	cin >> person1.addressofperson.numberofhouse_oraprtment;
	cout << "please enter your mothly salary? \n";
	cin >> person1.salaryofperson.Mothlysalary;
	person1.salaryofperson.yearlysalary = person1.salaryofperson.Mothlysalary * 12 ;
	cout << "please enter your facebook? \n";
	cin >> person1.contactofperson.facebook;
	cout << "please enter your instagram? \n";
	cin >> person1.contactofperson.instagram;
	cout << "please enter your inkedn? \n";
	cin >> person1.contactofperson.likedn;
	cout << "please enter your website? \n";
	cin >> person1.contactofperson.website;
	cout << "please enter your phone number? \n";
	cin >> person1.contactofperson.phonenumber;
	cout << "please enter your home phone number? \n";
	cin >> person1.contactofperson.homephonenumber;




	cout << "**********************************\n";
	cout << " NAME : " << person1.name << "\n";
	cout << " AGE : " << person1.age << "\n";
	cout << " CITY : " << person1.addressofperson.city << "\n";
	cout << " COUNTRY : " << person1.addressofperson.country << "\n";
	cout << " NUMBER OF POST : " << person1.addressofperson.numberofpost << "\n";
	cout << " STREET : " << person1.addressofperson.street << "\n";
	cout << " NUMBER OF HOUSE/APARTMENT : " << person1.addressofperson.numberofhouse_oraprtment << "\n";
	cout << " FACBOOKE : " << person1.contactofperson.facebook << "\n";
	cout << " INSTAGRAM : " << person1.contactofperson.instagram << "\n";
	cout << " LINKEDN : " << person1.contactofperson.likedn << "\n";
	cout << " WEBSITE : " << person1.contactofperson.website << "\n";
	cout << " PHONE NUMBER : " << person1.contactofperson.phonenumber << "\n";
	cout << " HOME PHONE NUMBER : " << person1.contactofperson.homephonenumber << "\n";
	cout << " MONTHLY SALARY : " << person1.salaryofperson.Mothlysalary << "\n";
	cout << " YEARLY SALARY : " << person1.salaryofperson.yearlysalary << "\n";
	cout << " GENDER : " << person1.gender << "\n";
	cout << " MARRIED : " << person1.ismarried << "\n";
	cout << "**********************************\n";


	return 0;
}