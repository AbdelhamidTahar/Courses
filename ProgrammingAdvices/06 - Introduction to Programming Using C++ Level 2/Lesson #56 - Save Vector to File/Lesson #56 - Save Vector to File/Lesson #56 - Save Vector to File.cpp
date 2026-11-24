#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void SaveVectorToFile(const string& FileName,vector<string>&vDate)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (string& Line : vDate)
		{
			if(Line !="")
			{
				MyFile << Line << endl;
			}
		}
	}
	MyFile.close();
}

void PrintFileData(const string& FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line = "";
		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}
	}
	MyFile.close();
}

int main()
{
	vector <string> vData{ "Ali","alla","","Hohammed","Sara","","Lana","Abdelhamid","Jack" };
	SaveVectorToFile("RandomData.txt", vData);

	PrintFileData("RandomData.txt");
	return 0;
}