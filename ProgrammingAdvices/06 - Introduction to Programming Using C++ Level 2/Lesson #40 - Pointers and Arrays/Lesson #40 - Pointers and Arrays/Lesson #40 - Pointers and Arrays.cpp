#include<iostream>
using namespace std;


int main()
{

	int Arr[] = { 12,43,88,564};
	int* Pa;
	Pa = Arr;
	cout << "Value Of POinter Is: " << Pa << endl;
	

	cout << "Addresses Array with Pointer: " << endl;
	cout << "Index 0 : " << (Pa) << endl;
	cout << "Index 1 : " << (Pa + 1) << endl;
	cout << "Index 2 : " << (Pa + 2) << endl;
	cout << "Index 3 : " << (Pa + 3) << endl;


	cout << endl;
	cout << "Values Of Array with Pointer: " << endl;
	cout << "Index 0 : " << *(Pa) << endl;
	cout << "Index 1 : " << *(Pa + 1) << endl;
	cout << "Index 2 : " << *(Pa + 2) << endl;
	cout << "Index 3 : " << *(Pa + 3) << endl;


	cout << endl;
	cout << "Addresses Array with FOr LOOp And Pointer: " << endl;
	for(int i = 0 ; i<=3;i++)
	{
		cout << "Index 0 : " << (Pa + i) << endl;
	}

	cout << endl;
	cout << "Value Of Array with FOOR LOOP And Pointer: " << endl;
	for (int i = 0; i <= 3; i++)
	{
		cout << "Index 0 : " << *(Pa + i) << endl;
	}



	return 0;
}