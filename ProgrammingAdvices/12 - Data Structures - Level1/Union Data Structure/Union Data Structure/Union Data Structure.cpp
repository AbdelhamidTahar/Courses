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

	FirstUnion.charvalue = 'q';
	cout << "The Char Value In First Union Is: " << FirstUnion.charvalue << endl;

	FirstUnion.floatvalue = 65.5435f;
	cout << "The Float Value In First Union Is: " << FirstUnion.floatvalue << endl;

	FirstUnion.intValue = 6666;
	cout << "The Int Value In First Union Is: " << FirstUnion.intValue << endl;


	cout << "_______________________________________________\n";


	SecondUnion.charvalue = 'Z';
	cout << "The Char Value In Second Union Is: " << SecondUnion.charvalue << endl;

	SecondUnion.floatvalue = 5.34f;
	cout << "The Float Value In Second Union Is: " << SecondUnion.floatvalue << endl;

	SecondUnion.intValue = 6547;
	cout << "The Int Value In Second Union Is: " << SecondUnion.intValue << endl;


	return 0;
}