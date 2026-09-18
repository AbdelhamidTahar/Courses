#include <iostream>
using namespace std;

class clsPerson
{
private:

	
	

public:
	int x = 00;
	void Print1(clsPerson Object)
	{
		Object.x = 100;
		cout << "X= " << Object.x << endl;
	};
	void Print2(clsPerson& Object)
	{
		Object.x = 600;
		cout << "X= " << Object.x << endl;
	};

};

int main()
{


	clsPerson Person1;

	//Pass Object By Value.
	Person1.Print1(Person1);
	cout << Person1.x << endl;

	// Pass Object By Reference.
	Person1.Print2(Person1);
	cout << Person1.x << endl;


	return 0;
}