#include <iostream>
#include<vector>
using namespace std;


int main()
{

	int x = 65464;

	int& a = x;
	int& y = x;
	int& z = x;
	int& j = x;
	int& t = x;

	cout << a << " " << &a << endl;
	cout << y << " " << &a << endl;
	cout << z << " " << &a << endl;
	cout << j << " " << &a << endl;
	cout << t << " " << &a << endl;



	return 0;
}