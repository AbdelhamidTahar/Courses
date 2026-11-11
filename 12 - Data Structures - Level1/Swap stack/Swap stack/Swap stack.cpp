#include<iostream>
#include <stack>
using namespace std;




int main()
{
	stack <int> MyStack1;
	stack <int> MyStack2;

	MyStack1.push(10);
	MyStack1.push(20);
	MyStack1.push(30);
	MyStack1.push(40);
	MyStack1.push(50);



	MyStack2.push(100);
	MyStack2.push(200);
	MyStack2.push(300);
	MyStack2.push(400);
	MyStack2.push(500);



	MyStack1.swap(MyStack2);

	cout << "\nStack 1  : ";
	while (!MyStack1.empty())
	{
		cout << MyStack1.top() << " ";
		MyStack1.pop();
	}

	cout << "\nStack 2  : ";
	while (!MyStack2.empty())
	{
		cout << MyStack2.top() << " ";
		MyStack2.pop();
	}


	return 0;
}