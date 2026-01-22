#include <iostream>
using namespace std;

void readgrades(float grades[3])
{
	cout << "please enter grade1?\n";
	cin >> grades[0];

	cout << "please enter grade2?\n";
	cin >> grades[1];

	cout << "please enter grade3?\n";
	cin >> grades[2];
}

float calculateavaregegrades(float grades[3])
{
	return (grades[0] + grades[1] + grades[2]) / 3;
}

int main()
{
	float grades[3];
	readgrades(grades);
	cout << "The average of grades is: " << calculateavaregegrades(grades) << endl;

	return 0;
}