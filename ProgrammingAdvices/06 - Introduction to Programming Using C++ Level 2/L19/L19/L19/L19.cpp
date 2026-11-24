#include <iostream>
using namespace std;

void PrintNumbers(int M, int N)
{
	if (M >= N)
	{
		cout << M << endl;
		PrintNumbers(M - 1, N);
	}
}

int main()
{
	PrintNumbers(10, 1);
}
