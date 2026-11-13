#include <iostream>
#include <queue>
using namespace std;

void SwapQueu(queue<int>& FirsQueu, queue<int>& SecondQueu)
{
	queue<int> TempQueu;

	TempQueu = FirsQueu;
	FirsQueu = SecondQueu;
	SecondQueu = TempQueu;
}

int main()
{
	queue<int>MyQueu;
	MyQueu.push(10);
	MyQueu.push(20);
	MyQueu.push(30);
	MyQueu.push(40);
	MyQueu.push(50);


	queue<int>MyQueu2;
	MyQueu2.push(100);
	MyQueu2.push(200);
	MyQueu2.push(300);
	MyQueu2.push(400);
	MyQueu2.push(500);


	MyQueu.swap(MyQueu2);
	cout << "The Elements after Swap Queus\n\n";


	cout << "The elements in queu 1 is : ";
	while (!MyQueu.empty())
	{
		cout << MyQueu.front() << " ";
		MyQueu.pop();
	}

	cout << endl;

	cout << "The elements in queu 2 is : ";
	while (!MyQueu2.empty())
	{
		cout << MyQueu2.front() << " ";
		MyQueu2.pop();
	}

	return 0;
}