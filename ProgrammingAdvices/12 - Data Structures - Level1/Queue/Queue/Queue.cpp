#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int>MyQueu;

	MyQueu.push(10);
	MyQueu.push(20);
	MyQueu.push(30);
	MyQueu.push(40);
	MyQueu.push(50);

	cout << "The number Of Elements Is: " << MyQueu.size() << endl;
	cout << "First Element To Push In Queu: " << MyQueu.front() << endl;
	cout << "Last Element To Push In Queu: " << MyQueu.back() << endl;

	cout << "\n\nThe Elements From First To Last is : ";
	while (!MyQueu.empty())
	{
		cout << MyQueu.front() << " ";
		MyQueu.pop();
		
	}

	return 0;
}