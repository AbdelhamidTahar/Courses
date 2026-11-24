#include <iostream>
using namespace std;

void readmak(float &mark)
{
	cin >> mark;
}

void readmarks(float marks[3])
{
	cout << "Please enter the mark1?" << endl;
	readmak(marks[0]);
	
	cout << "Please enter the mark2?" << endl;
	readmak(marks[1]);
	
	cout << "Please enter the mark3?" << endl;
	readmak(marks[2]);
}

float avg(float marks[3])
{
	return (marks[0] + marks[1] + marks[2]) / 3;
}

bool checkresult(float avg)
{
	return (avg >= 50);
}

void printrsult(float avg)
{
	cout << avg << "\n";
	if (checkresult(avg) == true)
	{
		cout << "PASS" << endl;
	}
	else
	{
		cout << "FIAL" << endl;
	}

}

int main()
{
	float marks[3];

	readmarks(marks);
	printrsult(avg(marks));

	return 0;
}