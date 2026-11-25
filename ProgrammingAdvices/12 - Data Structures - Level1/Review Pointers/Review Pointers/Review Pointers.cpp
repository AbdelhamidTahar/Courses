#include <iostream>
using namespace std;

int main()
{
	int x = 8;
	const int z = 88;

	// 1. Normal pointer to a normal variable.
	// The pointer can point to another variable, and the pointed-to value can be modified.
	int* ptr1 = &x;


	// 2. Normal pointer to a variable treated as const through this pointer.
	// The pointer can point to another variable, but the pointed-to value cannot be modified through this pointer.
	// Note: The original variable itself is not const.
	const int* ptr2 = &x;


	// 3. Constant pointer to a normal variable.
	// The pointer cannot point to another variable, but the pointed-to value can be modified.
	int* const ptr3 = &x;


	// 4. Constant pointer to a const variable.
	// The pointer cannot point to another variable, and the pointed-to value cannot be modified through this pointer.
	// The pointed-to variable is already const, so it must be accessed through a pointer to const.
	const int* const ptr4 = &z;

}