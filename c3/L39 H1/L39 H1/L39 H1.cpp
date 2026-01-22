#include <iostream>
using namespace std;

int main()
{

	float grades[3];

	cout << "Please Enter the grade1?" << endl;
	cin >> grades[0];

	cout << "Please Enter the grade2?" << endl;
	cin >> grades[1];

	cout << "Please Enter the grade3?" << endl;
	cin >> grades[2];

	float avg = (grades[0] + grades[1] + grades[2]) / 3;

	cout << "**************************\n";
	cout << "The average of grades is " << avg << endl;

	return 0;
}