#include <iostream>
using namespace std;

void readmark(float &mark)
{
	cout << "Please enter your mark" << endl;
	cin >> mark;
}

bool checkofresultexam(float mark)
{
	return (mark >= 50);
}

void printresult(bool result)
{
	if (result == true)
	{
		cout << "PASS" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
}

int main()
{
	float mark;

	readmark(mark);
	printresult(checkofresultexam(mark));

	return 0;
}