#include<iostream>
#include"clsString.h"
using namespace std;

int main()
{
    clsString S1("Abdelhaimd TAHAR 43--.");

   cout << "Upper All String: " << S1.UpperAllString() << endl;

   cout << "Lower All String: " << S1.LowerAllString() << endl;
    

    S1.PrintFirstLetterOfEachWord();
    cout << "\nUpper First Letter Of EachWord: " << S1.UpperFirstLetterOfEachWord() << endl;


    cout << "Lower First Letter Of EachWord: " << S1.LowerFirstLetterOfEachWord() << endl;

    cout << "Count Capital Letters: " << S1.CountCapitalLetters() << endl;

    cout << "Count Small Letters: " << S1.CountSmallLetters() << endl;

    cout << "Count All Letters: " << S1.CountLetters(S1.All)<< endl;

    cout << "Count Capital Letters: " << S1.CountLetters(S1.CapitalLetters)<< endl;

    cout << "Count Small Letters: " << S1.CountLetters(S1.SmallLetters)<< endl;

    cout << "Count Letter 't': " << S1.CountLetter('t') << endl;

    cout << "Count Vowels : " << S1.CountVowels() << endl;

    S1.PrintVowels();
    cout << endl;
    S1.PrintEachWordInString();

    cout << "\nCount Words: " << S1.CountWords() << endl;

    S1.SplitString(" ");

    cout << "Trim Rigth: " << S1.TrimRigth()<< endl;

    cout << "Trim Left: " << S1.TrimLeft() << endl;

    cout << "Trim : " << S1.Trim() <<  endl;

    cout << "Reverse Words: "<< S1.ReverseWordsInString() << endl;

    cout << "Replace Word In String Using Built In Function: "
        << S1.ReplaceWordInStringUsingBuiltInFunction("abdelhamid", "HAMID") << endl;

    cout << "Remove Punctuations From String: " <<S1.RemovePunctuationsFromString() << endl;


    cout << endl << endl;
    cout << " Object After all Edit :" << S1.Value << endl;

    
}

