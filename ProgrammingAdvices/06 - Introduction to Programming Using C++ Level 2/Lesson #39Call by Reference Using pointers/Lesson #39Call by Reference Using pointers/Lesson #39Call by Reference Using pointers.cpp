#include <iostream>
using namespace std;

void SwapByRef(int& Number1, int& Number2)
{
	int temp;
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
}

void SwapByPointers(int *P1, int *P2)
{
	int temp;
	temp = *P1;
	*P1 = *P2;
	*P2 = temp;
}


int main()
{

	int a, b;
	a = 12;
	b = 44;
	cout << "Value Of A Before using Call By Ref " << a << endl;
	cout << "Value Of B Before using Call By Ref " << b << endl;
	SwapByRef(a, b);
	cout << "\nValue Of A After using Call By Ref " << a << endl;
	cout << "Value Of B After using Call By Ref " << b << endl;



	int T1, T2;
	T1 = 55;
	T2 = 100;
	cout << "\nValue Of T1 Before using Call by Reference: Using pointers " << T1 << endl;
	cout << "Value Of T2 Before using Call by Reference: Using pointers " << T2 << endl;
	SwapByPointers(&T1,&T2 );
	cout << "\nValue Of T1 After using Call by Reference: Using pointers " << T1 << endl;
	cout << "Value Of T2 After using CCall by Reference: Using pointers " << T2 << endl;

	return 0;
}