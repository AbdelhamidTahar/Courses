#include <iostream>
using namespace std;

void ReadTriangleData(float &A , float &B)
{
	

	cout << "Please Enter Triangle Side A ?" << endl;
	cin >> A;

	cout << "Please Enter Triangle Base B ?" << endl;
	cin >> B;

	
}

float CircleAreaByITriangle(float A, float B)
{
	const float PI = 3.141592653589793238;
	float Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	float A, B;

	ReadTriangleData(A, B);
	PrintResult(CircleAreaByITriangle(A,B));

	return 0;
}