#include<iostream>
#include <stack>
using namespace std;

int main()
{
	stack <int> stkNumbers;

	stkNumbers.push(10);
	stkNumbers.push(20);
	stkNumbers.push(30);
	stkNumbers.push(40);
	stkNumbers.push(50);

	cout << "Stack has " << stkNumbers.size() << " Elements\n\n";

	while (!stkNumbers.empty())
	{
		cout << "This Top In This Round Is: " << stkNumbers.top() << endl;
		cout << "Delete This Top is Done\n\n";
		stkNumbers.pop();
	}

	return 0;
}