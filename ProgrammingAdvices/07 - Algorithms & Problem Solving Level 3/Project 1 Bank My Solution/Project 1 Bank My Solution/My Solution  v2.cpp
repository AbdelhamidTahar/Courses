#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";
enum eBankingOperation {
    ShowClientList = 1, AddNewClient = 2, DeleteClient = 3,
    UpdateClientInfo = 4, FindClient = 5, Exit = 6
};
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance =0;
    bool MarkForDelete = false;

};


//***************************************** General Funcs *****************************************************
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

string ReadString(const string &Message)
{
    string AccountNumber = "";
    cout << Message;
    cin >> AccountNumber;
    return AccountNumber;
}

//*************************************************************************************************************


//***************** Load Data From File To Vector *****************************

sClient ConvertLinetoRecord(const string &Line,const string &Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string todouble

    return Client;
}

vector <sClient> LoadCleintsDataFromFile(const string &FileName)
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








//***************** Print Main Menu *****************************
void PrintHeaderMainMenueScreen()
{
    cout << "===========================================\n";
    cout << "\tMain Menue Screen\n";
    cout << "===========================================\n";
}

void PrintChoicesMainMenuScreen()
{
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";

}

void PrintfooterMainMenueScreen()
{
    cout << "===========================================\n";
}

void PrintMainMenueScreen()
{
    PrintHeaderMainMenueScreen();
    PrintChoicesMainMenuScreen();
    PrintfooterMainMenueScreen();
}



//***************** Read Banking Operation *****************************
eBankingOperation ReadBankingOperation()
{
    short ChooseNumber = 0;
    cout << "Choose what do you want to do? [1 to 6]? ";
    cin >> ChooseNumber;

    return (eBankingOperation)ChooseNumber;
}



//***************** ( 1 ) Print Clients List *****************************
void PrintHeaderClienList(const vector <sClient>& vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void PrintClientRecord(const sClient& Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientsRecordsList(const vector <sClient>& vClients)
{
    for (const sClient &Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
}

void PrintfooterClienList()
{
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void PrintAllClientsData(const vector <sClient>& vClients)
{
    PrintHeaderClienList(vClients);
    PrintClientsRecordsList(vClients);
    PrintfooterClienList();
}





//***************** ( 2 ) Add New Client *****************************
void PrintHeaderAddClientScreen()
{
    cout << "---------------------------------------\n";
    cout << "\tAdding New Client Screen:\n";
    cout << "---------------------------------------\n";
}

string ConvertRecordToLine(const sClient &Client,const string &Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

void AddDataLineToFile(const string &FileName,const string &stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);
    {
        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

}

sClient ReadNewClient()
{
    sClient Client;



    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

void AddClient(const string &AccuntNumber)
{

    sClient Client;
    Client = ReadNewClient();
    Client.AccountNumber = AccuntNumber;
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

bool FindClientByAccountNumber(const string &AccountNumber,const vector<sClient> &vClients, sClient& Client)
{
    for (const sClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void AddClients(vector <sClient>& vClients)
{
    sClient Client;
    string AccountNumber;
    char AddMore = 'Y';

    do
    {
        AccountNumber = ReadString("Enter Accunt Number? ");
        while (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            AccountNumber = ReadString
            ("Client with [" + AccountNumber + "] already exists, Enter another Account Number ? ");
        }

        AddClient(AccountNumber);
        cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
        vClients = LoadCleintsDataFromFile(ClientsFileName);

        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');

}









//***************** ( 3 ) Delete Client *****************************
void PrintHeaderDeleteClientScreen()
{
    cout << "---------------------------------------\n";
    cout << "\tDelete Screen:\n";
    cout << "---------------------------------------\n";
}

void PrintClientCard(sClient Client)
{
    cout << "\n\n\nThe following are the client details:";
    cout << "\n--------------------------------------";
    cout << "\nAccout Number  : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n--------------------------------------\n";
}

bool MarkClientForDeleteByAccountNumber(const string &AccountNumber, vector <sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector <sClient> SaveCleintsDataToFile(const string &FileName,const vector<sClient> &vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (const sClient &C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool DeleteClientByAccountNumber(const string &AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";

            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}





//***************** ( 4 ) Update Client *****************************
void PrintHeaderUpdateClientScreen()
{
    cout << "---------------------------------------\n";
    cout << "\tUpdate Screen:\n";
    cout << "---------------------------------------\n";
}

sClient ChangeClientRecord(const string &AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool UpdateClientByAccountNumber(const string &AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveCleintsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}





//***************** ( 5 ) Find Client *****************************
void PrintHeaderFindClientScreen()
{
    cout << "---------------------------------------\n";
    cout << "\tFind Client Screen:\n";
    cout << "---------------------------------------\n";
}



//***************** ( 6 ) EXIT *****************************
void PrintExitScreen()
{
    cout << "---------------------------------------\n";
    cout << "\tProgram Ends :- )\n";
    cout << "---------------------------------------\n";
}



int main()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    eBankingOperation Operation;
    string AccountNumber;
    sClient Client;
    bool isExit = false;
    do
    {
        system("cls");
        PrintMainMenueScreen();
        Operation = ReadBankingOperation();


        switch (Operation)
        {

        case eBankingOperation::ShowClientList:
        {
            system("cls");
            PrintAllClientsData(vClients);

            cout << "\n\n\nPress any key to go back to Main Menue ...";
            system("pause>0");
            break;
        }
        case eBankingOperation::AddNewClient:
        {
            system("cls");
            PrintHeaderAddClientScreen();
            AddClients(vClients);

            cout << "\n\n\nPress any key to go back to Main Menue ...";
            system("pause>0");

            break;
        }
        case eBankingOperation::DeleteClient:
        {
            system("cls");
            PrintHeaderDeleteClientScreen();
            AccountNumber = ReadString("Enter Accunt Number? ");
            DeleteClientByAccountNumber(AccountNumber, vClients);

            cout << "\n\n\nPress any key to go back to Main Menue ...";
            system("pause>0");
            break;
        }
        case eBankingOperation::UpdateClientInfo:
        {
            system("cls");
            PrintHeaderUpdateClientScreen();
            AccountNumber = ReadString("Enter Accunt Number? ");
            UpdateClientByAccountNumber(AccountNumber, vClients);

            cout << "\n\n\nPress any key to go back to Main Menue ...";
            system("pause>0");

            break;
        }
        case eBankingOperation::FindClient:
        {
            system("cls");
            PrintHeaderFindClientScreen();
            AccountNumber = ReadString("Enter Accunt Number? ");
            if (FindClientByAccountNumber(AccountNumber, vClients, Client))
            {

                PrintClientCard(Client);
                cout << "\n\n\nPress any key to go back to Main Menue ...";
                system("pause>0");
            }
            else
            {
                cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
                cout << "\n\n\nPress any key to go back to Main Menue ...";
                system("pause>0");
            }



            break;
        }
        case eBankingOperation::Exit:
        {
            system("cls");
            PrintExitScreen();
            isExit = true;
            break;
        }


        }

    } while ((Operation < 1 || Operation > 6) || isExit == false);

    system("pause>0");
    return 0;
}


