#include <iostream>
#include <string>
using namespace std;


int main()
{
	int* P1;
	float* P2;
	bool* P3;
	char* P4;
	string* P5;

	P1 = new int;
	P2 = new float;
	P3 = new bool;
	P4 = new char;
	P5 = new string;


	*P1 = 678;
	*P2 = 678.5344f;
	*P3 = false;
	*P4 =  't';
	*P5 = "BBBD";

	cout << *P1 << endl;
	cout << *P2 << endl;
	cout << *P3 << endl;
	cout << *P4 << endl;
	cout << *P5 << endl;

	delete P1;
	delete P2;
	delete P3;
	delete P4;
	delete P5;

	P1 = new int;
	*P1 = 55567;
	cout << *P1 << endl;
	delete P1;


	void* Pv;
	Pv = new string;
	*(static_cast<string*>(Pv)) = "ttgh";
	cout << *(static_cast<string*>(Pv)) << endl;
	delete Pv;

	int* Arr = new int[3] ;
	*Arr = 55;
	*(Arr + 1) = 88;
	*(Arr + 2) = 99;

	cout << *Arr << endl;
	cout << *(Arr + 1)  << endl;
	cout << *(Arr + 2) << endl;

	delete Arr;

	return 0;
}