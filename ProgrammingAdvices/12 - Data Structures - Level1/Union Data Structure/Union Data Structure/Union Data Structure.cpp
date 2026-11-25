#include <iostream>
using namespace std;

int main()
{
	union MyUnion
	{
		int intValue;
		float floatvalue;
		char charvalue;
	};

	MyUnion FirstUnion, SecondUnion;

	cout << "_______________________________________________\n";
	cout << "\t\tAdrress Members in Union one:\n";
	cout << "Adrs Union One:" << &FirstUnion << endl;
	cout << "Adrs Union One Char:" <<(void*) & FirstUnion.charvalue << endl;
	cout << "Adrs Union One Int:" << &FirstUnion.intValue << endl;
	cout << "Adrs Union One Float:" << &FirstUnion.floatvalue << endl;
	cout << "_______________________________________________\n\n";


	FirstUnion.charvalue = 'q';
	cout << "The Char Value In First Union Is: " << FirstUnion.charvalue << endl;

	FirstUnion.floatvalue = 65.5435f;
	cout << "The Float Value In First Union Is: " << FirstUnion.floatvalue << endl;

	FirstUnion.intValue = 6666;
	cout << "The Int Value In First Union Is: " << FirstUnion.intValue << endl;


	cout << "_______________________________________________\n";


	return 0;
}