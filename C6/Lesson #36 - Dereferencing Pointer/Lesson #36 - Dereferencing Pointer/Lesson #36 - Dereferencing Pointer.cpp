#include <iostream>
using namespace std;

int main()
{

	int Number = 55;
	cout << "the Value of Number is: " << Number << endl;
	cout << "the Address of Number is: " << &Number << endl;

	int* PointerOfNumber = &Number;
	cout << "the Value Of Pointer Of Number Is: " << PointerOfNumber << endl;
	cout << "the Value Of Derefrencitg Pointer Of Number is: " << *PointerOfNumber << endl;

	*PointerOfNumber = 60;
	cout << "the Value Of Derefrencitg Pointer Of Number After Modifial is: " << *PointerOfNumber << endl;

	*PointerOfNumber = *PointerOfNumber + 10;
	cout << "the Value Of Derefrencitg Pointer Of Number After Modifial is: " << *PointerOfNumber << endl;
	cout << "the Value of Number is: " << Number << endl;


}

