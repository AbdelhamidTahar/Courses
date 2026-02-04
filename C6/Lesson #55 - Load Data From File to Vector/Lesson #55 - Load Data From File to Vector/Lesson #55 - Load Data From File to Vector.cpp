#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void LoadDataFromFileToVector(const string& FileName, vector<string>& vDataFile)
{
	fstream File;

	File.open(FileName, ios::in);
	if (File.is_open())
	{
		string Line = "";
		while (getline(File, Line))
		{
			vDataFile.push_back(Line);
		}
	}
	File.close();
}


int main()
{
	vector <string> vDataFile;
	LoadDataFromFileToVector("RandomData.txt", vDataFile);
	for (string& Line : vDataFile)
	{
		cout << Line << endl;
	}
	return 0;
}