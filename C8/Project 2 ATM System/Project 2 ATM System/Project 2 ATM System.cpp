#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";


enum enATMMenueOptions {
    eQuickWithdraw = 1, eNormlWithdraw = 2,
    eDeposit = 3, eChangrBalance = 4, eLogout = 5
};

enum enQuickWithdrawOptions {
    ewp1 = 20, ewp2 = 50, ewp3 = 1000, ewp4 = 200,
    ewp5 = 400, ewp6 = 600, ewp7 = 800, ewp8 = 1000, ewpExit = 9
};

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

sClient  CurrentClient;

void ShowATMMainMenue();

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

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


vector <sClient> LoadCleintsDataFromFile(string FileName)
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


bool FindClientByAccountNumberAndPinCode(string AccountNumber, string  PinCode, sClient& CurrentClient)
{

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            CurrentClient = C;
            return true;
        }

    }
    return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;
    else
        return false;
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void GoBackToATMMainMenue()
{
    cout << "\n\nPress any key to go back to ATM Menue...";
    system("pause>0");
    ShowATMMainMenue();

}

short ReadMQuickWithdrawMenuSecreenOption()
{
    cout << "Choose what to withdraw from[1] to [8] ? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}


bool IsBalanceEnough(sClient CLient, short Balance)
{
    return (CLient.AccountBalance >= Balance);
}

void GoBackShowQuickWithdrawMenuSecreen()
{
    cout << "\n\nPress any key to Countenu...";
    system("pause>0");
    ShowQuickWithdrawMenuSecreen();
}

void ShowQuickWithdrawMenuSecreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] 20          [2] 50\n";
    cout << "\t[3] 100         [4] 200\n";
    cout << "\t[5] 400         [6] 600\n";
    cout << "\t[7] 800         [8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance;
    
    short QuickWithdrhoice = ReadMQuickWithdrawMenuSecreenOption();
    if (QuickWithdrhoice > 0 && QuickWithdrhoice < 9)
    {
        if (IsBalanceEnough(CurrentClient, (enQuickWithdrawOptions)QuickWithdrhoice))
        {

        }
        else
        {
            cout << "The amount exceeds your balance, make another choice.\n";
            GoBackShowQuickWithdrawMenuSecreen();
        }
    }
    else
    {
        GoBackToATMMainMenue();
    }

}

void PerfromTranactionsMenueOption(enATMMenueOptions ATMMenueOptions)
{
    switch (ATMMenueOptions)
    {
    case enATMMenueOptions::eQuickWithdraw:
    {
        ShowQuickWithdrawMenuSecreen();
        GoBackToATMMainMenue();
    }
    }
}


void ShowATMMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    (enATMMenueOptions)ReadMainMenueOption();
  

}

void Login()
{
    string AccountNumber, PinCode;
    bool LoginFaild = false;

    do
    {
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid Username/Password!\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter Pin Code? ";
        cin >> PinCode;

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ShowATMMainMenue();
}