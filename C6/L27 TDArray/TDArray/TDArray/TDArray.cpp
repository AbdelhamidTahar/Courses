#include<iostream>
using namespace std;


void MultiplicationTableTDArr(int MultiplicationTable[10][10])
{

	for (int Rowe = 0; Rowe < 10; Rowe++)
	{
		for (int Column = 0; Column < 10; Column++)
		{
			MultiplicationTable[Rowe][Column] = (Rowe + 1) * (Column + 1);
		}
	}


}

void PrintTDArr(int MultiplicationTable[10][10])
{

	for (int Rowe = 0; Rowe < 10; Rowe++)
	{
		for (int Column = 0; Column < 10; Column++)
		{
			printf("%0*d ", 2, MultiplicationTable[Rowe][Column]);
		}
		cout << endl;
	}


}

int main()
{

	int MultiplicationTable[10][10];

	MultiplicationTableTDArr(MultiplicationTable);
	PrintTDArr(MultiplicationTable);


	return 0;
}