#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	fstream MyFile;
	


	MyFile.open("MyFile.text",ios::out |ios::app);//gust add text in the back.
	if (MyFile.is_open())
	{
		for (int i = 0; i <=100; i++)
		{
			MyFile << i << endl;
		}
	}
	MyFile.close();


	return 0;
}