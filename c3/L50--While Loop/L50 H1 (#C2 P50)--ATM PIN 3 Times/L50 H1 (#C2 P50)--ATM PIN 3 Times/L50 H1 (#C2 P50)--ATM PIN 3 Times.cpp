#include <iostream>
using namespace std;

void ReadPINCode(int& PINCode)
{
	cout << "Please enter yor PIN Code?\n";
	cin >> PINCode;
}

void PrintBalance(int &PINCode)
{
	int FailedCounter = 0;
	int Balance = 7500;

	if (PINCode == 5151)
	{
		 
		cout << "Your balance is: " << Balance << endl;
	}
	else
	{
		
		while (PINCode != 5151 && FailedCounter < 2)
		{
			FailedCounter++;
			ReadPINCode(PINCode);
			
		}
		
		
		if (FailedCounter == 2)
		{
			if (PINCode == 5151 )
			{
              cout << "Your balance is: " << Balance << endl;
			}
			else
			{
				cout << "Card Locked" << endl;
			}

		}
		else
		{
			cout << "Your balance is: " << Balance << endl;
		}

	}
}



int main()
{
	int PINCode;

	ReadPINCode(PINCode);
	PrintBalance(PINCode);


	return 0;
}