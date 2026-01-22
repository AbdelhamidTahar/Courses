#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please Enter A Number" << endl;
	cin >> Number;

	return Number;
}

void PowerOf_2_3_4(int Number)
{
	int A, B, C;

	A = Number * Number;
	B = Number * Number * Number;
	C = Number * Number * Number * Number;
	cout << A << " " << B << " " << C << endl;
}
int main()
{

	PowerOf_2_3_4(ReadNumber());

	return 0;
}