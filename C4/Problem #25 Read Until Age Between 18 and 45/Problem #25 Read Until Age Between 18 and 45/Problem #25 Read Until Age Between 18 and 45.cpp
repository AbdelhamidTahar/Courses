#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;

	cout << "Please Enter Your Age ?" << endl;
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

int ReadUntilAgeBetween(int From, int To)
{

	int Age = 0;

	do
	{
		Age = ReadAge();

		
	} while (!ValidateNumberInRange(Age, From, To));
	return Age;

}

void PritResult(int Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
		cout << "\nValid Age" << endl;
	else
		cout << "\nInvalid Age" << endl;
}

int main()
{

	PritResult(ReadUntilAgeBetween(18,45));


	return 0;
}