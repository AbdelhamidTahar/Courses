#include <iostream>
#include <cmath>

using namespace std;

void ReadNumbers(float& A, float& D)
{
	cout << "Pmease Enter Rectengel Side A ? " << endl;
	cin >> A;

	cout << "Pmease Enter Rectengel Side D ? " << endl;
	cin >> D;
}

float RectangleareaAreaBySideandDiagonal(float A, float D)
{
	float Area = A *  sqrt(pow(D, 2) - pow(A, 2));
	return Area;
}

void PrintResult(float Area)
{
	cout << "\nRectengel Area = " << Area << endl;
}

int main()
{
	float A, D;

	ReadNumbers(A, D);
	PrintResult(RectangleareaAreaBySideandDiagonal(A, D));


	return 0;
}
