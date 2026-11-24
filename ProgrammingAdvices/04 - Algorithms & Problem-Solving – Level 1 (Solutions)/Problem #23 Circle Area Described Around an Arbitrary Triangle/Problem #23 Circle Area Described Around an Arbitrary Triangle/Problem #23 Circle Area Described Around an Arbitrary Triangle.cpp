#include <iostream>
using namespace std;

void ReadTriangleData(float& A, float& B , float& C)
{


	cout << "Please Enter Triangle Side A ?" << endl;
	cin >> A;

	cout << "Please Enter Triangle Base B ?" << endl;
	cin >> B;

	cout << "Please Enter Triangle Side C ?" << endl;
	cin >> C;

}

float CircleAreaByATriangle(float A, float B,float C)
{
	const float PI = 3.141592653589793238;

	float P = (A + B + C) / 2;

	float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));

	float Area = pow(T, 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	float A, B,C;

	ReadTriangleData(A, B, C);
	PrintResult(CircleAreaByATriangle(A, B, C));

	return 0;
}