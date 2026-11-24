#include <iostream>
using namespace std;

class clsA
{
public:
	int x = 1;

};

class clsB:public clsA
{
public:
	int z = 2;
};


int main()
{
	clsA A;
	clsA B;

	//UP CASTING
	// true casting because clsA is in clsB.
	// so B have A so we can casting B to A.
	// because B Has member of A.
	clsA* BaseA = &B;
	cout << BaseA->x << endl;



	// DOWNG CASTING
	// false casting because A not have B .
	//so we can"t casting A to B because A don"t Have memebers B.
	//clsB* BaseB = &A;



	return 0;
}