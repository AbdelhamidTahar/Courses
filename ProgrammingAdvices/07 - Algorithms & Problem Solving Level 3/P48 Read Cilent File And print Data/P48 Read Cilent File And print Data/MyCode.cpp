#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";


struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};


vector<string>SplitString(string S, const string& Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S.find(Delim)) != std::string::npos)
    {
        sWord = S.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S.erase(0, pos + Delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S != "")
    {
        vString.push_back(S); // it adds last word of the string.
    }
    return vString;
}

void LoadDataFromFileToVector(const string& FileName, vector<string>& vDataFile)
{
    fstream MyFile;
    string Line = "";
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {

        while (getline(MyFile, Line))
        {
            vDataFile.push_back(Line);
        }
    }
    MyFile.close();
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double

    return Client;
}

void PrintHeader()
{

    cout << "-------------------------------------------------------------------------------------------------------\n";
    cout << "| Account Number   | Pin Code  | Client Name                           | Phone             |Balance\n";
    cout << "-------------------------------------------------------------------------------------------------------\n";

}

void PrintBody(sClient Client)
{

    cout << "| " << setw(17) << left << Client.AccountNumber
        << "| " << setw(10) << Client.PinCode
        << "| " << setw(38) << Client.Name
        << "| " << setw(18) << Client.Phone
        << "| " << setw(20) << Client.AccountBalance << endl;

}

void PrintDataClientsFromFile()
{
    vector<string> vDataFile;
    LoadDataFromFileToVector(ClientsFileName, vDataFile);

    cout << setw(50) << "Client List (" << vDataFile.size() << ") Client(s).\n";
    PrintHeader();
    sClient Client;
    for (string& LineData : vDataFile)
    {
        Client = ConvertLinetoRecord(LineData);
        PrintBody(Client);
    }
}

int main()
{

    PrintDataClientsFromFile();
    return 0;
}