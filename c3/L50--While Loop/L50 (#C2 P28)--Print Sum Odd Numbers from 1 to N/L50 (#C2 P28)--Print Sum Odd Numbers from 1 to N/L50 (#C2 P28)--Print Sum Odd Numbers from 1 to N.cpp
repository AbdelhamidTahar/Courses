#include <iostream>
using namespace std;

void ReadNumber(int &Number)
{
	cout << "Please enter a number?" << endl;
	cin >> Number; 
}

int SumOddNumbersfrom1toN(int Number)
{
	int Sum = 0;
	while (Number >= 1)
	{
		if (Number % 2 != 0)
		{
			Sum += Number;
		}
		Number--;
	}
	return Sum;
}

void PrintSumOddNumbersfrom1toN(int Sum)
{
	
	cout << Sum << endl;

}

int main()
{

	int Number;
	ReadNumber(Number);
	PrintSumOddNumbersfrom1toN( SumOddNumbersfrom1toN(Number) );

	return 0;
}