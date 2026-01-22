#include <iostream>
using namespace std;

enum genders{male=1,famel=0};
enum married_status {married=1 , singal =0};
enum colors {red,green,blue,orange,purpel};

int main()
{


	string name;
	string city;
	unsigned short age;
	string country;
	float mothlys_salary;
	genders gender;
	married_status is_married;
	colors myfavoritecolor;

	
	name = "HAMID";
	age = 23;
	city = "tebessa";
	country = "algirea";
	mothlys_salary = 60000.00;
	gender = genders::male;
	is_married = married_status::singal;
	myfavoritecolor = colors::orange;
	

	cout << "****************************\n";
	cout << "Name : " << name << "\n";
	cout << "Age : " << age << "\n";
	cout << "City : " << city << "\n";
	cout << "Country : " << country << "\n";
	cout << "Mothly Salary : " << mothlys_salary << "\n";
	cout << "Yearly Salary : " << mothlys_salary * 12  << "\n";
	cout << "Gendar : " << gender << "\n";
	cout << "Married : " << is_married << "\n";
	cout << "Fivert color : " << myfavoritecolor << "\n";
	cout << "****************************\n";

	return 0;

};