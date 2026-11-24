#include <iostream>
using namespace std;

int main()
{

	bool result; 

	result = (5 > 6 && 7 == 7) || (1 || 0);
	cout << result << "\n";

	result = !(5>6 && 7==7)||(1 || 0);
	cout << result << "\n";

	result = !(5 > 6 && 7 == 7) || !(1 || 0);
	cout << result << "\n";

	result = !(5 > 6 && 7 == 7) && !(1 || 0);
	cout << result << "\n";

	result = ((5>6 && 7<=8) || (8>1 && 4 <= 3 )) && true;
	cout << result << "\n";

	result = ((5 > 6 &&    !(7    <=    8)) && (8 > 1 || 4 <= 3)) || true;
	cout << result << "\n";

	return 0; 
}