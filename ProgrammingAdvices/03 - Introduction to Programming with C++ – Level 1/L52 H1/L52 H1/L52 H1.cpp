#include <iostream>
using namespace std;

int PositionNumberInArray(int Arr[10])
{
	for (int i = 0; i <= 9; i++)
	{
		cout << "Your are in itiratin: " << i + 1 << "\n";
		if (Arr[i] == 20)
		{
			return i;
			break;
		}
	}
	
}

void PrintPosition(int Position)
{
	cout << "Fiwen at Position Number: " << Position << endl;
}

int main()
{
	int Arr[10] = { 10,20,44,55,33,22,99,88,99,100 };

	PrintPosition( PositionNumberInArray(Arr) );


	return 0;
}