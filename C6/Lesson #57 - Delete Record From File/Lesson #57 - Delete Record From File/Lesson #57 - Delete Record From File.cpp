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

void SaveVectorToFile(const string& FileName, vector<string>& const vDate)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (string& Line : vDate)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
	}
	MyFile.close();
}

void DeleteRecordFile(const string& FileName,const string &Record)
{
	vector <string> vNames;
	LoadDataFromFileToVector(FileName, vNames);

	for (string& Line : vNames)
	{
		if (Line == Record)
		{
			Line = "";
		}
	}

	SaveVectorToFile(FileName, vNames);

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

	cout << "Print Data File Befor Edit\n\n";
	PrintFileData("Names.txt");

	DeleteRecordFile("Names.txt", "Ali");

	cout << "\n\nPrint Data File After Edit\n\n";
	PrintFileData("Names.txt");

	return 0;
}