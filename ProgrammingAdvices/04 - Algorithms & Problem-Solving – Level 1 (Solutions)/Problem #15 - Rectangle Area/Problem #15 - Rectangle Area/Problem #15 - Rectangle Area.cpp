#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& B)
{
	cout << "Pmease Enter Rectengel Width A ? " << endl;
	cin >> A;

	cout << "Pmease Enter Rectengel Width B ? " << endl;
	cin >> B;
}

float CalculateRectengelArea(float A, float B)
{
	return A * B;
}

void PrintResult(float Area)
{
	cout << "\nRectengel Area = " << Area << endl;
}

int main()
{
	float A, B;

	ReadNumbers(A, B);
	PrintResult(CalculateRectengelArea(A, B));


	return 0;
}
