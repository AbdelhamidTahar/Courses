#include <iostream>
using namespace std;

void ReadNumbers(int& A, int& B, int& C)
{
	cout << "Please Enter The Number 1?" << endl;
	cin >> A;

	cout << "Please Enter The Number 2?" << endl;
	cin >> B;

	cout << "Please Enter The Number 3?" << endl;
	cin >> C;
}

int MaxOfNumbers(int A, int B, int C)
{
	if (A > B)
		if (A > C)
			return A;
		else
			return C;
	else
		if (B > C)
			return B;
		else
			return C;
}

void PrintResult(int Max)
{
	cout << "\nThe Maximum Number Is: " << Max << endl;
}

int main()
{

	int  A,B,C;

	ReadNumbers(A, B, C);
	PrintResult(MaxOfNumbers(A, B, C));

	return 0;
}