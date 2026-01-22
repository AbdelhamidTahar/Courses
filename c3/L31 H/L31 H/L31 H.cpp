#include <iostream>
#include<string>
using namespace std;

int main()
{
	string string1, string2, string3;

	cout << "Please enter string1?" << endl;
	getline(cin, string1);
	cout << "\n";

	cout << "Please enter string2?" << endl;
	cin >> string2;
	cout << "\n";

	cout << "Please enter string3?" << endl;
	cin >> string3;

	cout << "*******************************\n";
	cout << "The length of string 1 is:" << string1.length() << "\n";
	cout << "Characters at 0,2,4,7 are:" << string1[0] << " " << string1[2] << " " << string1[4] << " " << string1[7] << "\n";
	cout << "Concatenating string2 and string3 =" + string2 + string3 << "\n";

	int result = stoi(string2) + stoi(string3);
	cout << string2 << " * " << string3 << " = " << result << endl;


	return 0;
}