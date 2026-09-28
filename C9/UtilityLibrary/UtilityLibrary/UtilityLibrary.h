#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"

using namespace std;


class UtilityLibrary
{
public:

	enum enCharTayp { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixChars = 5 };



	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}	
	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate Temp;
		Temp = A;
		A = B;
		B = Temp;
	}



	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{
		// rand() int حجمه مثل = يعطي رقم عشوائي عادة يكون الرقم كبير مثلا 87513
		int RandNum = rand() % (To - From + 1) + From;
		// 87513 % "10" ( 10 - 1 +1 ) = 3 + 1 = 4
		return RandNum; // 4
	}
	static char GetRandomCharacter(enCharTayp CharType)
	{
		switch (CharType)
		{
		case enCharTayp::SmallLetter:
		{
			return char(RandomNumber(97, 122)); // char( 110 ) = n
			break;
		}
		case enCharTayp::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharTayp::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharTayp::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharTayp::MixChars:
		{
			return char(RandomNumber(48, 122));
			break;
		}
		}
	}
	static string GenerateWord(enCharTayp CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++) // 1 <= 4 ? | 2 <= 4 ...
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharTayp CharType)
	{
		string Key = "";
		Key =       GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys, enCharTayp CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Kay [" << i << "] : " << GenerateKey(CharType) << endl;
		}
	}
	static void FillArrayWithRandomNumbers(int arr[100], int& arrLength,int From, int To)
	{

		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To); 
	}
	static void FillArrayWithRandomWords(string arr[100], int& arrLength, enCharTayp CharType, int& WordLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, WordLength);
	}
	static void FillArrayWithRandomKeys(string arr[100], int& arrLength, enCharTayp CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (short i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
		}
		return t;

	}
	static string EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text; // Ucggf
	}
	static string DecryptionText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}



};

