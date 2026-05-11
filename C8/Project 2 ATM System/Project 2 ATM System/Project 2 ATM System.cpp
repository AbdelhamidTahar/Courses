#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowQuickWithdrawMenuSecreen();
void ShowNormalWithdrawSecreen();
void Login();

enum enATMMenueOptions {
    eQuickWithdraw = 1, eNormalWithdraw = 2,
    eDeposit = 3, eCheckrBalance = 4, eLogout = 5
};

enum enQuickWithdrawOptions {
    ewp1 = 1, ewp2 = 2, ewp3 = 3, ewp4 = 4,
    ewp5 = 5, ewp6 = 6, ewp7 = 7, ewp8 = 8, ewpExit = 9
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

short ReadMainATMMenueOption()
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


bool IsBalanceEnough(sClient CLient, double Balance)
{
    return (CLient.AccountBalance >= Balance);
}

void GoBackShowQuickWithdrawMenuSecreen()
{
    cout << "\n\nPress any key to Countenu...";
    system("pause>0");
    ShowQuickWithdrawMenuSecreen();
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


vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
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


bool DepositBalanceToClientByAccountNumberATM(string AccountNumber, double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                CurrentClient = C;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }


        return false;
    }

}

void DepositQuickWithdrawBalanceOptions(string AccountNumber, double Amount)
{
    if (IsBalanceEnough(CurrentClient, Amount))
    {
        vector<sClient>vClients = LoadCleintsDataFromFile(ClientsFileName);
        DepositBalanceToClientByAccountNumberATM(CurrentClient.AccountNumber, Amount * -1, vClients);
    }
    else
    {
        cout << "The amount exceeds your balance, make another choice.";

    }
}

void PerfromQuickWithdrawMenueOption(enQuickWithdrawOptions QuickWithdrawOptions)
{
    switch (QuickWithdrawOptions)
    {

    case enQuickWithdrawOptions::ewp1:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber, 20);
        GoBackToATMMainMenue();
    }
    case enQuickWithdrawOptions::ewp2:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber,50);
        GoBackToATMMainMenue();
    }
    case enQuickWithdrawOptions::ewp3:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber, 100);
        GoBackToATMMainMenue();
    }
    case enQuickWithdrawOptions::ewp4:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber, 200);
        GoBackToATMMainMenue();
    }
    case enQuickWithdrawOptions::ewp5:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber, 400);
        GoBackToATMMainMenue();
    }
    case enQuickWithdrawOptions::ewp6:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber, 600);
        GoBackToATMMainMenue();
    }
    case enQuickWithdrawOptions::ewp7:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber, 800);
        GoBackToATMMainMenue();
    }
    case enQuickWithdrawOptions::ewp8:
    {
        DepositQuickWithdrawBalanceOptions(CurrentClient.AccountNumber, 1000);
        GoBackToATMMainMenue();
    }
        
    case enQuickWithdrawOptions::ewpExit:
    {
        GoBackToATMMainMenue();
        break;
    }
    
    }
}

void ShowQuickWithdrawMenuSecreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Quick With draw Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] 20          [2] 50\n";
    cout << "\t[3] 100         [4] 200\n";
    cout << "\t[5] 400         [6] 600\n";
    cout << "\t[7] 800         [8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance;
    
    PerfromQuickWithdrawMenueOption((enQuickWithdrawOptions)ReadMQuickWithdrawMenuSecreenOption());
 

}



void GoBackShowNormalWithdrawSecreen()
{

    cout << "\n\nPress any key to Countenu...";
    system("pause>0");
    system("cls");
    ShowNormalWithdrawSecreen();
}

double ReadAmount(string Message)
{
    double Amount = 0;
    do
    {
        cout << Message;
        cin >> Amount;
    } while (Amount <= 0);

        return Amount;
}

bool IsHasEnoughBalance(string AcountNumber, double Amount)
{
    vector<sClient>vclients = LoadCleintsDataFromFile(ClientsFileName);
    for (sClient Client : vclients)
    {
        if (Client.AccountNumber == AcountNumber)
        {
            return (Client.AccountBalance >= Amount);
        }
    }
    return false;
}

bool IsNumberMultipleOfX(int Amount, int X)
{
    double Reminder;
    Reminder = Amount % X;
    return (Reminder == 0)?true:false;
}

void NormalWithdraw()
{
    bool HasEnoughBalance = true;
    bool IsAmountMultipleOfX = false;
    double Amount;

    do
    {
        Amount = ReadAmount("\nEnter an amount multiple of 5's ? ");
        HasEnoughBalance = IsHasEnoughBalance(CurrentClient.AccountNumber, Amount);

        if (HasEnoughBalance)
        {
            IsAmountMultipleOfX = IsNumberMultipleOfX((int)Amount, 5);

            if (IsAmountMultipleOfX == true)
            {
                vector<sClient>vclients = LoadCleintsDataFromFile(ClientsFileName);
                DepositBalanceToClientByAccountNumberATM(CurrentClient.AccountNumber, Amount * -1, vclients);
                break;
            }
        }
        else
        {
            cout << "\n\Enter execceds your balanc, make another choice.";
            cout << "\n\nPress any key to Countenu...";
            system("pause>0");
            system("cls");
            cout << "\n-----------------------------------\n";
            cout << "\tNormal Withdraw Screen";
            cout << "\n-----------------------------------\n";
        }

    } while (HasEnoughBalance == false || IsAmountMultipleOfX == false);



}

void ShowNormalWithdrawSecreen()
{ 

    cout << "\n-----------------------------------\n";
    cout << "\tNormal Withdraw Screen";
    cout << "\n-----------------------------------\n";
    NormalWithdraw();

}

void Deposit()
{
    double Amount;
    do 
    {
        cout << "Enter a positive Deposit Amount? ";
        cin >> Amount;

    } while (Amount < 0);
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumberATM(CurrentClient.AccountNumber, Amount, vClients);

}

void ShowDepositSecreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";
    Deposit();
}


void CheckBalanceSecreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tCheck Balance Screen";
    cout << "\n-----------------------------------\n";

    cout << "Your Balance is: "<< CurrentClient.AccountBalance;
}


void PerfromMainATMMenueOption(enATMMenueOptions ATMMenueOptions)
{
    switch (ATMMenueOptions)
    {
    case enATMMenueOptions::eQuickWithdraw:
    {
        system("cls");
        ShowQuickWithdrawMenuSecreen();
        GoBackToATMMainMenue();
        break;
    }
    case enATMMenueOptions::eNormalWithdraw:
    {
        system("cls");
        ShowNormalWithdrawSecreen();
        GoBackToATMMainMenue();
        break;
    }
    case enATMMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositSecreen();
        GoBackToATMMainMenue();

    }
    case enATMMenueOptions::eCheckrBalance:
    {
        system("cls");
        CheckBalanceSecreen();
        GoBackToATMMainMenue();

    }
    case enATMMenueOptions::eLogout:
        Login();
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
    PerfromMainATMMenueOption((enATMMenueOptions)ReadMainATMMenueOption());
  

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

int main()
{
    Login();

    return 0;
}