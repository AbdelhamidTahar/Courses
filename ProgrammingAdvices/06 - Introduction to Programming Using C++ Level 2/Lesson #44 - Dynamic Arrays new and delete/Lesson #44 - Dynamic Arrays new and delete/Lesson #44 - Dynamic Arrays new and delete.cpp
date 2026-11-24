#include<iostream>
using namespace std;


int main()
{

	int NumberOfstudent = 0;

	cout << "How Many Number Of Student Do You Want To Enter Grades? ";
	cin >> NumberOfstudent;


	float* PtrArr;
	PtrArr = new float[NumberOfstudent];

	cout << "Enter Degres students\n\n";
	for (int i = 0; i < NumberOfstudent;i++)
	{
		cout << "Please Enter Degres The student Number " << i + 1<<": ";
		cin >> *(PtrArr + i);
	}

	cout << endl;
	for (int i = 0; i < NumberOfstudent; i++)
	{
		cout << "Grade Of The student Number " << i + 1 << ": ";
		cout << *(PtrArr + i) << endl;
	}

	delete[] PtrArr;

	return 0;
}