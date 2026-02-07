#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


namespace OperationsOnTheFile
{
    void CreatFile(const string& FileName);
    void FillFileConntent(const string& FileName, const string& Text);
    void ReadFileConntent(const string& FileName);
    void LoadDataFromFileToVector(const string& FileName, vector<string>& vDataFile);
    void SaveDataFromVectorToFile(const string& FileName, const vector<string>& vDate);
    void EditRecordFile(const string& FileName, const string& Record, const string& EditTo);
    void DeleteRecordFile(const string& FileName, const string& Record);
}

    void OperationsOnTheFile::CreatFile(const string& FileName)
    {
        fstream File;

        do
        {

            File.open(FileName, ios::out | ios::app);

        } while (!File.is_open());
        File.close();

    }
    void OperationsOnTheFile::FillFileConntent(const string& FileName, const string& Text)
    {
        fstream File;

        File.open(FileName, ios::out | ios::app);
        if (File.is_open())
        {

                File << Text << "\n";
           
        }
        File.close();
    }
    void OperationsOnTheFile::ReadFileConntent(const string& FileName)
    {


        fstream File;

        File.open(FileName + ".text", ios::in);

        if (File.is_open())
        {
            string Line = "";
            while (getline(File, Line))
            {
                cout << Line << "\n";;
            }

        }
        File.close();

    }
    void OperationsOnTheFile::LoadDataFromFileToVector(const string& FileName, vector<string>& vDataFile)
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
    void OperationsOnTheFile::SaveDataFromVectorToFile(const string& FileName, const vector<string>& vDate)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out);
        if (MyFile.is_open())
        {
            for (const string& Line : vDate)
            {
                if (Line != "")
                {
                    MyFile << Line << "\n";
                }
            }
        }
        MyFile.close();
    }
    void OperationsOnTheFile::EditRecordFile(const string& FileName, const string& Record, const string& EditTo)
    {
        vector <string> vNames;
        OperationsOnTheFile::LoadDataFromFileToVector(FileName, vNames);

        for (string& Line : vNames)
        {
            if (Line == Record)
            {
                Line = EditTo;
            }
        }

        SaveDataFromVectorToFile(FileName, vNames);

    }
    void OperationsOnTheFile::DeleteRecordFile(const string& FileName, const string& Record)
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

        OperationsOnTheFile::SaveDataFromVectorToFile(FileName, vNames);

    }



