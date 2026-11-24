#include <iostream>
using namespace std;




int ReadAndCalculatSum(int &Number)
{
	int Sum = 0;

	for (int i = 1; i <= 5; i++)
	{
		cout << "Please enter a number\n";
		cin >> Number;
		if (Number > 50)
		{
			continue;
			
		}
		Sum += Number;
	}
	return Sum;
}

void PrintSum(int Sum)
{
	cout << Sum << endl;
}

int main()
{

	int Number;

	
	PrintSum( ReadAndCalculatSum(Number) );

	return 0;
}