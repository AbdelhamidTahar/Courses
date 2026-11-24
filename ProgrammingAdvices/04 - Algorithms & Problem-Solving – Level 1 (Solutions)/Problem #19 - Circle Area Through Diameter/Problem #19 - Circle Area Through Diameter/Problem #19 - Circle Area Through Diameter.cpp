#include <iostream>
using namespace std;

float ReadRadious()
{
	float D;

	cout << "Please Enter Radious D ?" << endl;
	cin >> D;

	return D;
}

float CircleAreaByDiameter(float D)
{
	const float PI = 3.141592653589793238;
	float Area = ( pow(D, 2) * PI ) / 4;

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{

	PrintResult(CircleAreaByDiameter(ReadRadious()));

	return 0;
}