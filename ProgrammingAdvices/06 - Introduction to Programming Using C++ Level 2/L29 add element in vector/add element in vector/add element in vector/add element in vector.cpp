#include<iostream>
#include<vector>

using namespace std;

void ReadNumbers(vector <int>& vNumbers)
{
	int Number = 0;
	char MoreNumber;
	do
	{
		cout << "PLease Enter A NUmber? \n";
		cin >> Number;
		vNumbers.push_back(Number);
		cout << "Do You Want Add More  NUmbers? \n";
		cin >> MoreNumber;

	} while (MoreNumber == 'Y' || MoreNumber == 'y');
}

void PrintNumbers(vector <int>& vNumbers)
{

	for (int& Number : vNumbers)
	{

		cout << Number << " ";


	}

}

int main()
{


	vector <int> vNumbers;

	ReadNumbers(vNumbers);
	PrintNumbers(vNumbers);




	return 0;
}