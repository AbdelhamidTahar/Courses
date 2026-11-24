#include <iostream>
using namespace std;

void readnumber(int& number)
{

	cout << "Please enter the number" << endl; 
	cin >> number; 

}

void printnumbers(int number)
{
	
	for (number; number !=0; number--)
	{
		cout << number << endl;
	}
}

int main()
{
	int number;

	readnumber(number);
	printnumbers(number);

	return 0;
}