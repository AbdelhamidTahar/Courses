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

void PritResult(int Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
		cout << "\nValid Age" << endl;
	else
		cout << "\nInvalid Age" << endl;
}

int main()
{

	PritResult(ReadAge());


	return 0;
}