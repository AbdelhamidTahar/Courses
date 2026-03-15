#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

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

sClient ConvertLinetoRecord(const string& Line, const string& Seperator = "#//#")
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

vector <sClient> LoadCleintsDataFromFile(const string& FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number  : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

bool FindClientByAccountNumber(const string& AccountNumber, sClient& Client, vector <sClient>& vClients)
{

    vClients = LoadCleintsDataFromFile(ClientsFileName);
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}


string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}


void SaveVectorToFile(string FileName, vector <string>vData)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (string& Line : vData)
        {
            MyFile << Line << endl;
        }
        MyFile.close();
    }
}

void DeleteClientByAccountNumber(sClient& Client, vector <sClient>& vClients)
{
    vector <string> vLinesClients;

    for (sClient& C : vClients)
    {
        if (C.AccountNumber != Client.AccountNumber)
        {
            vLinesClients.push_back(ConvertRecordToLine(C));
        }
    }

    SaveVectorToFile(ClientsFileName, vLinesClients);

}

char AskDeletClientAccount()
{
    char DoYouWantDeletClient = 'Y';
    cout << "\nAre You Want To Delet This Client? y/n ";
    cin >> DoYouWantDeletClient;
    return toupper(DoYouWantDeletClient);
}

int main()
{
    sClient Client;
    vector <sClient> vClients;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, Client, vClients))
    {
        PrintClientCard(Client);
        if (AskDeletClientAccount() == 'Y')
        {
            DeleteClientByAccountNumber(Client, vClients);
            cout << "\n\nClient Delet Successfully.\n\n";
        }
    }
    else
    {
        cout << "\n\nClient with Account Number (" << AccountNumber <<
            ") is Not Found!";
    }

    return 0;
}