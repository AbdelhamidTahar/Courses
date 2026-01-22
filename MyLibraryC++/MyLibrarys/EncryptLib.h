#pragma once

#include <iostream>
#include <string>
using namespace std;





namespace Encryption
{
    string EncryptText(string Text, short EncryptionKey);
}
namespace Decrypt
{
    string DecryptText(string Text, short EncryptionKey);
}


string Encryption::EncryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}



string Decrypt::DecryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}