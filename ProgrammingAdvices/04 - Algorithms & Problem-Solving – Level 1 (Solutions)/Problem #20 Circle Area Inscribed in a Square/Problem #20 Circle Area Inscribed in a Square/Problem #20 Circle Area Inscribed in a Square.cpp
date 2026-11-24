#include <iostream>
using namespace std;

float ReadSquareSide()
{
	float A;

	cout << "Please Enter Radious D ?" << endl;
	cin >> A;

	return A;
}

float CircleAreaInscribedInSquare(float A)
{
	const float PI = 3.141592653589793238;
	float Area = (PI * pow(A, 2)) / 4;

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{

	PrintResult(CircleAreaInscribedInSquare(ReadSquareSide()));

	return 0;
}