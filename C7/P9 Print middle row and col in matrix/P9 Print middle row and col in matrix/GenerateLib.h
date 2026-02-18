#pragma once

#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;




namespace Generates
{
  
    enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

    int RandomNumber(int From, int To);

    char GetRandomCharacter(enCharType CharType);

    string GenerateWord(enCharType CharType, short Length);

    string GenerateKey();

    void GenerateKeys(short NumberOfKeys);

    string GeneratePassword(int LengthOfPassword);


}


int Generates::RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char Generates::GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SamallLetter:
    {
        // Generate a random lowercase letter (ASCII: 97 'a' to 122 'z').
        return char(RandomNumber(97, 122));
        break; // break is not necessary after return.
    }
    case enCharType::CapitalLetter:
    {
        // Generate a random uppercase letter (ASCII: 65 'A' to 90 'Z').
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        // Generate a random special character (ASCII: 33 '!' to 47 '/').
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        // Generate a random digit (ASCII: 48 '0' to 57 '9').
        return char(RandomNumber(48, 57));
        break;
    }
    }
    // If no valid type is provided, return a null character.
    return '\0';
}

string Generates::GenerateWord(enCharType CharType, short Length)
{
    string Word;  // Initialize an empty string to build the word.

    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

string Generates::GenerateKey()
{
    string Key = "";  // Initialize an empty key string.

    // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
}

void Generates::GenerateKeys(short NumberOfKeys)
{
    // Loop from 1 to NumberOfKeys.
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        // Print the current key number and the generated key.
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}

string Generates::GeneratePassword(int LengthOfPassword)
{

    string Password = "";

    for (int i = 1; i <= LengthOfPassword; i++)
    {

        enCharType CharType = (enCharType)RandomNumber(1, 4);
        Password += GetRandomCharacter(CharType);

    }


    return Password;
}