#include <iostream>
using namespace std; 

int main()
{

	bool result;

	result = 12 >= 12;
	cout << result << "\n";

	result = 12 > 7;
	cout << result << "\n";

	result = 8<6;
	cout << result << "\n";

	result = 8 == 8;
	cout << result << "\n";

	result = 7==5;
	cout << result << "\n";

	result = !(12>=12);
	cout << result << "\n";

	result = !(12 <7);
	cout << result << "\n";

	result = !(8<6);
	cout << result << "\n";

	result = !(8==8);
	cout << result << "\n";

	result = !(12 <= 12);
	cout << result << "\n";

	result = !(7==5);
	cout << result << "\n";

	result = 1 && 1;
	cout << result << "\n";

	result = true && 0;
	cout << result << "\n";

	result = 0 || 1;
	cout << result << "\n";

	result = 0 || 0;
	cout << result << "\n";

	result = !0;
	cout << result << "\n";

	result = !(1 || 0);
	cout << result << "\n";

	result = (7 == 7) && (7 > 5);
	cout << result << "\n";

	result = (7 == 7) && (7 < 5);
	cout << result << "\n";

	result = (7 == 7) || (7 < 5);
	cout << result << "\n";

	result = (7 < 7) || (7 > 5);
	cout << result << "\n";

	result = !(7 == 7) && (7 > 5);
	cout << result << "\n";

	result = (7 == 7) && !(7 < 5);
	cout << result << "\n";


	return 0;
}