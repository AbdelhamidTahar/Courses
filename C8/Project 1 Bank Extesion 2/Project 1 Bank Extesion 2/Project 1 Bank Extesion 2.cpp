#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";


void ShowMainMenue();
void ShowTransactionsMenue();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;


};

struct sUser
{
    string Name;
    string PassWord;
    short Permesions;
};

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

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
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
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }


            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return false;


}

sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }


    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

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

void PrintClientRecordLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void PrintClientRecordBalanceLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowAllClientsScreen()
{


    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void ShowTotalBalances()
{

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;

            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;

}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";

}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{

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

sClient ChangeClientRecord(string AccountNumber)
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
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

void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        //system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";


        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
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

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
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

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
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
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }


        return false;
    }

}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();

}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";

}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";

}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";


    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();


    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }


    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);

}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();


    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    //Validate that the amount does not exceeds the balance
    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);

}

void ShowTotalBalancesScreen()
{

    ShowTotalBalances();

}

enum enTransactionsMenueOptions {
    eDeposit = 1, eWithdraw = 2,
    eShowTotalBalance = 3, eShowMainMenue = 4
};

enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eManageUsers = 7, eLogout = 8
};

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();

}

void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();

}

void GoBackToManageUsersManu()
{
    cout << "\n\nPress any key to go back toManageUsersManu...";
    system("pause>0");
    ShowMainMenue();

}


short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eWithdraw:
    {
        system("cls");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    }


    case enTransactionsMenueOptions::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;
    }


    case enTransactionsMenueOptions::eShowMainMenue:
    {

        ShowMainMenue();

    }
    }

}

void ShowTransactionsMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PrintMessagewhinUserDoNotHavPermesions()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    cout << "\nAccess Denied,\nYou dont Have Permission To Do this,";
    cout << "\nPlease Conact Your Admin.";
}

void PerfromMainMenueOption(sUser sUserExist , enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        if(IsHeHasPermesions(sUserExist,eListClients))
        {
            system("cls");
            ShowAllClientsScreen();
        }
        else
        {
            PrintMessagewhinUserDoNotHavPermesions();
        }
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eAddNewClient:
    {
        if (IsHeHasPermesions(sUserExist, eAddNewClient))
        {
            system("cls");
            ShowAddNewClientsScreen();
        }
        else
        {
            PrintMessagewhinUserDoNotHavPermesions();
        }
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eDeleteClient:
    {
        if (IsHeHasPermesions(sUserExist, eDeleteClient))
        {
            system("cls");
            ShowDeleteClientScreen();
        }
        else
        {
            PrintMessagewhinUserDoNotHavPermesions();
        }
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eUpdateClient:
    {
        if (IsHeHasPermesions(sUserExist, eUpdateClient))
        {
            system("cls");
            ShowUpdateClientScreen();
        }
        else
        {
            PrintMessagewhinUserDoNotHavPermesions();
        }
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eFindClient:
    {
        if (IsHeHasPermesions(sUserExist, eFindClient))
        {
            system("cls");
            ShowFindClientScreen();
        }
        else
        {
            PrintMessagewhinUserDoNotHavPermesions();
        }
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eShowTransactionsMenue:
    {
        if (IsHeHasPermesions(sUserExist, eShowTransactionsMenue))
        {
            system("cls");
            ShowTransactionsMenue();
        }
        else
        {
            PrintMessagewhinUserDoNotHavPermesions();
            GoBackToMainMenue();
        }
        break;
    }
    case enMainMenueOptions::eManageUsers:
    {
        if (IsHeHasPermesions(sUserExist, eManageUsers))
        {
            system("cls");
            ShowManageUsersMenueScreen();
        }
        else
        {
            PrintMessagewhinUserDoNotHavPermesions();
            GoBackToMainMenue();
        }
        break;
    }
    case enMainMenueOptions::eLogout:
    {
            system("cls");
            ShowEndScreen();
        break;
    }
    }

}

enum enManageUsersOptions {
    eListUsers = 1, eAddNewUser = 2,
    eDeleteUser = 3, eUpdateUser = 4,
    eFindUser = 5, eShowMainMenue = 6
};

short ReadManageUsersManuOptions()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void GoBackToManageUsersManu()
{
    cout << "\n\nPress any key to go back to Manage Users Menue...";
    system("pause>0");
    ShowManageUsersMenueScreen();

}

void PerfromManageUsersManuOptions(enManageUsersOptions ManageUsersManuOptions)
{
    switch (ManageUsersManuOptions)
    {
    case enManageUsersOptions::eListUsers:
    {
        system("cls");
        ShowListtUserScreen();
        GoBackToManageUsersManu();
        break;
    }
    case enManageUsersOptions::eAddNewUser:
    {
        system("cls");
        ShowAddUserScreen();
        GoBackToManageUsersManu();
        break;
    }
    case enManageUsersOptions::eDeleteUser:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersManu();
        break;
    }
    case enManageUsersOptions::eUpdateUser:
    {
        system("cls");
        ShowUppdatetUserScreen();
        GoBackToManageUsersManu();
        break;
    }
    case enManageUsersOptions::eFindUser:
    {
        system("cls");
        ShowFindUserScreen();
        GoBackToManageUsersManu();
        break;
    }
    case enManageUsersOptions::eShowMainMenue:
    {

        ShowMainMenue();

    }
    }

}



void ShowManageUsersMenueScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tManage Users Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===========================================\n";
    PerfromManageUsersManuOptions((enManageUsersOptions)ReadManageUsersManuOptions());
}




void ShowMainMenue(sUser sUserExist)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption(sUserExist,(enMainMenueOptions)ReadMainMenueOption());
}






enum ePermissions
{
    epShowClientList = 1, epAddNewClient = 2, epDeleteClient = 4,
    epUpdateClientInfo = 8, epFindClient = 16, epTransactions = 32,
    epManageUsers = 46

};

//===================================================== 1Users List
void PrintUserRecordLine(sUser User)
{

    cout << "| " << setw(15) << left << User.Name;
    cout << "| " << setw(10) << left << User.PassWord;
    cout << "| " << setw(40) << left << User.Permesions;


}

void ShowListtUserScreen()
{
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);


    cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permesions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;



        for (sUser &Users : vUsers)
        {

            PrintUserRecordLine(Users);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}



//===================================================== 2 Add New User

sUser ConvertUserLinetoRecord(string Line, string Seperator = "#//#")
{

    sUser User;
    vector<string> vUserData;

    vUserData = SplitString(Line, Seperator);

    User.Name = vUserData[0];
    User.PassWord = vUserData[1];
    User.Permesions = stoi(vUserData[2]);




    return User;

}

bool IsUserPasswordRigth(string& UserPassword, sUser &User)
{
    return (UserPassword == User.PassWord);
}

short ReadUserPermissions()
{
    short Permissions = 0;
    char AskPermission = 'n';

    cout << "\nDo you want to give full access? y/n? ";
    cin >> AskPermission;

    if (AskPermission == 'y')
        return -1;


    cout << "\nDo you want to give access to :\n ";

    cout << "\nShow Client List? y/n? \n ";
    cin >> AskPermission;
    Permissions = (AskPermission == 'y') ? Permissions += epShowClientList : Permissions;


    cout << "\nAdd New Client? y/n? \n ";
    cin >> AskPermission;
    Permissions = (AskPermission == 'y') ? Permissions += epAddNewClient : Permissions;

    cout << "\nDelete Client? y/n? \n ";
    cin >> AskPermission;
    Permissions = (AskPermission == 'y') ? Permissions += epDeleteClient : Permissions;

    cout << "\nUpdate Client Info? y/n? \n ";
    cin >> AskPermission;
    Permissions = (AskPermission == 'y') ? Permissions += epUpdateClientInfo : Permissions;

    cout << "\nFind Client? y/n? \n ";
    cin >> AskPermission;
    Permissions = (AskPermission == 'y') ? Permissions += epFindClient : Permissions;

    cout << "\nTransactions? y/n? \n ";
    cin >> AskPermission;
    Permissions = (AskPermission == 'y') ? Permissions += epTransactions : Permissions;

    cout << "\nManage Users? y/n? \n ";
    cin >> AskPermission;
    Permissions = (AskPermission == 'y') ? Permissions += epManageUsers : Permissions;


    return (Permissions == 127) ? -1 : Permissions;
}

vector <sUser> LoadUsersDataFromFile(string FileName)
{

    vector <sUser> vUsers;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sUser User;

        while (getline(MyFile, Line))
        {

            User = ConvertUserLinetoRecord(Line);

            vUsers.push_back(User);
        }

        MyFile.close();

    }

    return vUsers;

}

string ConvertRecordToLine(sUser User, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += User.Name + Seperator;
    stClientRecord += User.PassWord + Seperator;
    stClientRecord += to_string(User.Permesions) ;



    return stClientRecord;

}

sUser ReadUserInfo(string& UserName)
{
    sUser User;
    User.Name = UserName;
    cout << "\nEnter Password? ";
    getline(cin >> ws, User.PassWord);
    User.Permesions = ReadUserPermissions();

    return User;
}

bool IsUserExist(string& UserName, vector <sUser>& vUsers,sUser &sUserExist)
{
    for (sUser& User : vUsers)
    {
        if (User.Name == UserName)
        {
            sUserExist = User;
            return true;
        }
    }
    return false;
}

void ShowAddUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd User Screen";
    cout << "\n-----------------------------------\n";

    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    sUser User; 
    char AsKAddMoreUsers = 'n';

    do
    {
        cout << "\nEnter Username? ";
        getline(cin >> ws, User.Name);

        while (IsUserExist(User.Name, vUsers, User))
        {
            cout << "\nUser With[" << User.Name << "] already exists, Enter another Username? ";
            getline(cin >> ws, User.Name);
        }

        User = ReadUserInfo(User.Name);
        AddDataLineToFile(UsersFileName, ConvertRecordToLine(User));
        cout << "User Added Successfully, do you want to add more Users? Y/N? ";
        cin >> AsKAddMoreUsers;

    } while (AsKAddMoreUsers == 'y');
}

//===================================================== 3 Delet User

bool IsThisUserAdmin(sUser User)
{
    return (User.Permesions == -1);
}

vector <sUser> SaveUsersDataToFile(string FileName, vector <sUser> vUsers,string UserNameDontSave="")
{
    string DataLine;
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sUser C : vUsers)
        {

            if (C.Name != UserNameDontSave)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vUsers;

}

void ShowDeleteUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelet User Screen";
    cout << "\n-----------------------------------\n";
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    sUser User;



        cout << "\nEnter User name? ";
        getline(cin >> ws, User.Name);

        if (IsUserExist(User.Name, vUsers, User))
        {
            if (IsThisUserAdmin(User))
            {
                cout << "\nYou can not Delete This User.\n";
            }
            else
            {
                SaveUsersDataToFile(UsersFileName, vUsers, User.Name);
            }
        }
        else
        {
            cout << "\nSorry User [" << User.Name << "] Is Not Excest.";
        }
    
}

//===================================================== 4 Uppdate User

void PrintUserCard(sUser User)
{
    cout << "\nThe following are the User details:\n";
    cout << "-----------------------------------";
    cout << "\nUser Name   : " << User.Name;
    cout << "\nPasword     : " << User.PassWord;
    cout << "\nPermesions  : " << User.Permesions;
    cout << "\n-----------------------------------\n";
}

void ShowUppdatetUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate User Screen";
    cout << "\n-----------------------------------\n";
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    sUser User;

    cout << "\nEnter User name? ";
    getline(cin >> ws, User.Name);

    if (IsUserExist(User.Name, vUsers, User))
    {
        PrintUserCard(User);
        User = ReadUserInfo(User.Name);
        for (sUser& TempUser : vUsers)
        {
            if (TempUser.Name == User.Name)
            {
                TempUser = User;
                break;
            }
        }
        SaveUsersDataToFile(UsersFileName, vUsers);
    }
    else
    {
        cout << "\nSorry User [" << User.Name << "] Is Not Excest.";
    }

}

//===================================================== 5 Find User
void ShowFindUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------------\n";

    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    sUser User;

    cout << "\nEnter User name? ";
    getline(cin >> ws, User.Name);

    if (IsUserExist(User.Name, vUsers, User))
        PrintUserCard(User);
    else
        cout << "\nSorry User [" << User.Name << "] Is Not Excest.";

}

//=====================================================

bool IsHeHasPermesions(sUser User, enMainMenueOptions eOption)
{
    return ((User.Permesions & eOption) != 0);
}



void Login()
{
    cout << "\n-----------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n-----------------------------------\n";

    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "Enter User Name? ";
    string UserName;
    getline(cin >> ws, UserName);

    cout << "Enter Password? ";
    string PassWord;
    getline(cin >> ws, PassWord);

    sUser sUserExist;
    if (IsUserExist(UserName, vUsers, sUserExist) && IsUserPasswordRigth(PassWord, sUserExist))
    {
        ShowMainMenue(sUserExist);
    }
}

int main()

{
    Login();
    system("pause>0");
    return 0;
}