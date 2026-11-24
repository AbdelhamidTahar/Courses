#include <iostream>
#include<vector>
using namespace std;


int main()
{

	vector <int> vNumbers;

	cout << "Is Vectore Has Elementes Befor Add:" << vNumbers.empty() << endl;
	cout << "Vectore Size Befor Add :" << vNumbers.size() << endl;


	cout << "\nAdd Elementes\n";
	for (int i = 10 ; i <= 20 ; i++)
	{

		vNumbers.push_back(i);
		cout << "\nAdd Element Done\n";
		cout << "Is Vectore Has Elementes Before Add Element: " << vNumbers.empty() << endl;
		cout << "Vectore Size Before Add Element : " << vNumbers.size() << endl;
	
	}
	


	cout << "\nIs Vectore Has Elementes After Add All Element: " << vNumbers.empty() << endl;
	cout << "Vectore Size After Add  All Element : " << vNumbers.size() << endl;

	int VectorElement = 0;
	cout << " \nVectore Elementes:" << endl;
	for (int& Number : vNumbers)
	{
		

		printf("Element[%d]: %d \n", ++VectorElement, Number);


	}

	VectorElement = 0;
	cout << " \nVectore Elementes Delete:\n" << endl;
	for (int& Number : vNumbers)
	{

		vNumbers.pop_back();
		printf("Element[%d]:Delete\n", ++VectorElement );
		
		cout << "Is Vector Has Element Before Delete Element" << vNumbers.empty() << endl;
		cout << "Size Vector Before Delete Element" << vNumbers.size() << endl;

	}


	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.clear();


	return 0;
}