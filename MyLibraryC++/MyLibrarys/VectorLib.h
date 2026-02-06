#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace OperationsOnTheVector
{
	void AddElementToVector(vector<int>& vNumbers, const int& Number);
	void AddElementToVector(vector<float>& vNumbers, const float& Number);
	void AddElementToVector(vector<double>& vNumbers, const double& Number);
	void AddElementToVector(vector<char>& vChars, const char& Character);
	void AddElementToVector(vector<string>& vStrings, const string& text);
	void AddElementToVector(vector<bool>& vbooleans, const bool& Boolean);

	int FindElementPositionInVector(const vector<int>& vNumbers, const int& Number);
	int FindElementPositionInVector(const vector<float>& vNumbers, const float& Number);
	int FindElementPositionInVector(const vector<double>& vNumbers, const double& Number);
	int FindElementPositionInVector(const vector<char>& vChars, const char& Number);
	int FindElementPositionInVector(const vector<string>& vString, const string& Number);
};

namespace CheckVector
{


	bool IsElementInVector(const vector<int>& vNumbers, const int& Element);
	bool IsElementInVector(const vector<float>& vNumbers, const float& Element);
	bool IsElementInVector(const vector<double>& vNumbers, const double& Element);
	bool IsElementInVector(const vector<char>& vChars, const char& Element);
	bool IsElementInVector(const vector<string>& vString, const string& Element);


	bool IsPalindromeVector(const vector<int>& vNumbers);
	bool IsPalindromeVector(const vector<float>& vNumbers);
	bool IsPalindromeVector(const vector<double>& vNumbers);
	bool IsPalindromeVector(const vector<char>& vChars);
	bool IsPalindromeVector(const vector<string>& vStrings);
	bool IsPalindromeVector(const vector<bool>& vBooleans);


}

void OperationsOnTheVector::AddElementToVector(vector<int> &vNumbers,const int &Number)
{
	vNumbers.push_back(Number);
}

void OperationsOnTheVector::AddElementToVector(vector<float> &vNumbers, const float& Number)
{
	vNumbers.push_back(Number);
}

void OperationsOnTheVector::AddElementToVector(vector<double> &vNumbers, const double& Number)
{
	vNumbers.push_back(Number);
}

void OperationsOnTheVector::AddElementToVector(vector<char>& vChars, const char& Character)
{
	vChars.push_back(Character);
}

void OperationsOnTheVector::AddElementToVector(vector<string>& vStrings, const string& text)
{
	vStrings.push_back(text);
}

void OperationsOnTheVector::AddElementToVector(vector<bool>& vbooleans, const bool& Boolean)
{
	vbooleans.push_back(Boolean);
}



int OperationsOnTheVector::FindElementPositionInVector(const vector<int>& vNumbers, const int& ElementToFind)
{
	unsigned int LengthOfVector = vNumbers.size();
	for (int i = 0; i < LengthOfVector; i++)
	{
		if (vNumbers[i] == ElementToFind )
		{
			return i;
		}
	}
	return -1;
}

int OperationsOnTheVector::FindElementPositionInVector(const vector<float>& vNumbers, const float &ElementToFind)
{
	unsigned int LengthOfVector = vNumbers.size();
	for (int i = 0; i < LengthOfVector; i++)
	{
		if (vNumbers[i] == ElementToFind)
		{
			return i;
		}
	}
	return -1;
}

int OperationsOnTheVector::FindElementPositionInVector(const vector<double>& vNumbers, const double& ElementToFind)
{
	unsigned int LengthOfVector = vNumbers.size();
	for (int i = 0; i < LengthOfVector; i++)
	{
		if (vNumbers[i] == ElementToFind)
		{
			return i;
		}
	}
	return -1;
}

int OperationsOnTheVector::FindElementPositionInVector(const vector<char>& vChars, const char& ElementToFind)
{
	unsigned int LengthOfVector = vChars.size();
	for (int i = 0; i < LengthOfVector; i++)
	{
		if (vChars[i] == ElementToFind)
		{
			return i;
		}
	}
	return -1;
}

int OperationsOnTheVector::FindElementPositionInVector(const vector<string>& vStrings, const string& ElementToFind)
{
	unsigned int LengthOfVector = vStrings.size();
	for (int i = 0; i < LengthOfVector; i++)
	{
		if (vStrings[i] == ElementToFind)
		{
			return i;
		}
	}
	return -1;
}



bool CheckVector::IsElementInVector(const vector<int>& vNumbers,const int& Element)
{
	return (OperationsOnTheVector::FindElementPositionInVector(vNumbers, Element) != -1);
}

bool CheckVector::IsElementInVector(const vector<float>& vNumbers, const float& Element)
{
	return (OperationsOnTheVector::FindElementPositionInVector(vNumbers, Element) != -1);
}

bool CheckVector::IsElementInVector(const vector<double>& vNumbers, const double& Element)
{
	return (OperationsOnTheVector::FindElementPositionInVector(vNumbers, Element) != -1);
}

bool CheckVector::IsElementInVector(const vector<char>& vChars, const char& Element)
{
	return (OperationsOnTheVector::FindElementPositionInVector(vChars, Element) != -1);
}

bool CheckVector::IsElementInVector(const vector<string>& vStrings, const string& Element)
{
	return (OperationsOnTheVector::FindElementPositionInVector(vStrings, Element) != -1);
}


bool CheckVector::IsPalindromeVector(const vector<int>& vNumbers)
{

	int VectorLength = vNumbers.size();
	for (int i = 0; i < VectorLength / 2; i++)
	{
		if (vNumbers[i] != vNumbers[VectorLength - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool CheckVector::IsPalindromeVector(const vector<float>& vNumbers)
{

	int VectorLength = vNumbers.size();
	for (int i = 0; i < VectorLength / 2; i++)
	{
		if (vNumbers[i] != vNumbers[VectorLength - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool CheckVector::IsPalindromeVector(const vector<double>& vNumbers)
{

	int VectorLength = vNumbers.size();
	for (int i = 0; i < VectorLength / 2; i++)
	{
		if (vNumbers[i] != vNumbers[VectorLength - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool CheckVector::IsPalindromeVector(const vector<char>& vChars)
{

	int VectorLength = vChars.size();
	for (int i = 0; i < VectorLength / 2; i++)
	{
		if (vChars[i] != vChars[VectorLength - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool CheckVector::IsPalindromeVector(const vector<string>& vStrings)
{

	int VectorLength = vStrings.size();
	for (int i = 0; i < VectorLength / 2; i++)
	{
		if (vStrings[i] != vStrings[VectorLength - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool CheckVector::IsPalindromeVector(const vector<bool>& vBooleans)
{

	int VectorLength = vBooleans.size();
	for (int i = 0; i < VectorLength / 2; i++)
	{
		if (vBooleans[i] != vBooleans[VectorLength - i - 1])
		{
			return false;
		}
	}
	return true;
}