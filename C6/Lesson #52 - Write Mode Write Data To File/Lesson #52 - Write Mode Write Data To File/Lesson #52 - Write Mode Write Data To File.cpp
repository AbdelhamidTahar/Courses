#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream MyFile1;
	fstream MyFile2;

	MyFile1.open("MyFirstFile.text", ios::out);//ios::out is the write Mod.
	MyFile2.open("MySecondeFile.text", ios::out);//ios::out is the write Mod.
	
	if (MyFile1.is_open() && MyFile2.is_open())
	{

		MyFile1 << "This is My First Line\n";
		MyFile1 << "This is My second Line\n";
		MyFile1 << "This is My therd Line\n";

		MyFile2 << "This is My First Line\n";
		MyFile2 << "This is My second Line\n";
		MyFile2 << "This is My therd Line\n";


		MyFile1.close();
		MyFile2.close();
	}


	

	return 0;
}