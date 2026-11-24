#include <iostream>
using namespace std;


int main()
{


	char Arr1[] = { '1','0','1' };
	int i = 0;

	for (char n: Arr1)
	{
		cout << "[" << i++ << "] " << n << endl;
	}
	


	return 0;
}
