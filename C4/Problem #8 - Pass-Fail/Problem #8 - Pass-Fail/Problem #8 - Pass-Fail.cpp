#include <iostream>
using namespace std;

enum enPassFail{Pass=1,Fail=2};

int ReadNumber()
{
	int Mark;

	cout << "Please Enter Your Mark?" << endl;
	cin >> Mark;

	return Mark;
}

enPassFail CheckMark(int Mark)
{
	if (Mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResults(int Mark)
{
	if (CheckMark(Mark) == enPassFail::Pass)
		cout << "\nYou Passed";
	else
		cout << "\nYou Falild";
}

int main()
{

	PrintResults( ReadNumber() );

	return 0;
}