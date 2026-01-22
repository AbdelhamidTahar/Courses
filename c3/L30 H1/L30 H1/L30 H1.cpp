#include <iostream>
#include <string>
using namespace std; 

int main()
{

	string str1 = "43.22";

	double doub1;
	doub1 = stod(str1);
	cout << "Convert STR1 to DOUBLE=" << doub1 << "\n";

	float flo1;
	flo1 = stof(str1);
	cout << "Convert STR1 to FLOAT=" << flo1 << "\n";

	int in1;
	in1 = stoi(str1);
	cout << "Convert STR1 to INTEGER=" << in1 << "\n";


	int n1 = 20;
	string n1_str;
	n1_str = to_string(n1);
	cout << "Convert N1 to STRING=" << in1 << "\n";

	double n2 = 33.5;
	string n2_str;
	n2_str = to_string(n2);
	cout << "Convert N2 to STRING=" << n2_str << "\n";

	float n3 = 55.23;
	string n3_str;
	n3_str = to_string(n3);
	cout << "Convert N3 to STRING=" << n3_str << "\n";
	int n3_int;
	n3_int = n3;
	cout << "Convert N3 to INTEGER=" << n3_int << "\n";
	n3_int = (int)n3;
	cout << "Convert N3 to INTEGER=" << n3_int << "\n";
	n3_int = int(n3);
	cout << "Convert N3 to INTEGER=" << n3_int << "\n";


	return 0;
}