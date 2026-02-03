#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void CreatFill(const string& FileName)
{
    fstream File;

    do
    {

        File.open(FileName + ".text", ios::out | ios::app);
      
    } while (!File.is_open());
    File.close();
   
}
void FillFileConntent(const string &FileName)
{
    fstream File;

    File.open(FileName+".text", ios::out | ios::app);
        if (File.is_open())
        {
            for(int i = 0 ; i<100;i++)
            {
                File << "Hello\n";
            }
        }
        File.close();
}
void ReadFileConntent(const string& FileName)
{

  
    fstream File;

    File.open(FileName + ".text", ios::in);

    if (File.is_open())
    {
        string Line = "";
        while (getline(File, Line))
        {
            cout << Line << endl;
        }

    }
    File.close();
   
}

int main()
{

    string FileName = "TestFile";
    CreatFill(FileName);
    FillFileConntent(FileName);
    ReadFileConntent(FileName);
}
