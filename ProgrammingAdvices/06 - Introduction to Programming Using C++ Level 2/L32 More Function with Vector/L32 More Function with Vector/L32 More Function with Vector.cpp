#include <iostream>
#include<vector>
using namespace std;


int main()
{

	vector <int> vNumbers = { 543,543,65,2,45,435,43,6,54,6,54 };

	vNumbers.push_back(890);

	vNumbers.front(); // first element in vector
	vNumbers.back();// last element in vector
	vNumbers.pop_back();// delet laset element in vector
	vNumbers.size();// how many element in vector
	vNumbers.capacity(); // “The capacity of a vector is the number of elements 
	//it can store in memory right now without needing to 
   // allocate more space.”
	vNumbers.clear();// delet all elements in vector


	return 0;
}