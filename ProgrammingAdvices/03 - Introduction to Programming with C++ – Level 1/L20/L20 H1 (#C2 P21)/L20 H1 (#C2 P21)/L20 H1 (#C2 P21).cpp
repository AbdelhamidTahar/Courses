#include <iostream>
using namespace std;

int main()
{

	float l;

	cout << "Please enter value of L \n";
	cin >> l ;

	const float pi = 3.14;
	float area;

	
	area = (l * l) / (4 * pi);

	cout << area << "\n";



	return 0;
}
